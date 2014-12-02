//PP6MuonAnalysis file - Functionality to analyse a particle data file using classes
//----------------------------------------------------------------------------------
#include "PP6Math.hpp"
#include "PP6MuonAnalysis.hpp"
#include "Particle.hpp"
#include "FourVector.hpp"
#include "ThreeVector.hpp"
#include "FileReader.hpp"

#include <iostream>
#include <climits>
#include <cmath>
#include <cstring>

//Definition for PP6MuonAnalysis function
void muonAnalysis()
{
	std::string file;
		
	//Ask for user input of file
	std::cout << "Input name of file to be analysed" << std::endl;
	
	std::cin >> file;
	
	//Check for invalid input	
	while (!std::cin)
	{
		std::cerr << "Error in input of file name" << std::endl;
		//Clear buffer to reset for next loop
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');

		std::cin >> file;
	}
	
	//Check how large the file is
	FileReader g(file);
	int size = 0;
	if (g.isValid())
	{
		g.nextLine();
		while (g.nextLine())
		{
			//Check input
			if (g.inputFailed()) break;

			size++;
		}
	}	
	
	Particle particle[size];
	int eventnum[size];
	std::string datasource[size];
	std::string name;

	FileReader f(file);

	//Check that file is valid
	if (f.isValid())
	{
		f.nextLine();
		int j = 0;
		while (f.nextLine())
		{
			//Retrieve event number as integer
			eventnum[j] = f.getFieldAsInt(1);

			//Retrieve particle name as string
			name = f.getFieldAsString(2);
			if (name == "e-")
			{
				particle[j].setPDGCode(11);
			}
			else if (name == "e+")
			{
				particle[j].setPDGCode(-11);
			}
			else if (name == "mu-")
			{
				particle[j].setPDGCode(13);
			}
			else if (name == "mu+")
			{
				particle[j].setPDGCode(-13);
			}
			else if (name == "pi+")
			{
				particle[j].setPDGCode(211);
			}
			else if (name == "pi-")
			{
				particle[j].setPDGCode(-211);
			}
			else if (name == "K+")
			{
				particle[j].setPDGCode(321);
			}
			else if (name == "K-")
			{
				particle[j].setPDGCode(-321);
			}
			else if (name == "p+")
			{
				particle[j].setPDGCode(2212);
			}
			else if (name == "p-")
			{
				particle[j].setPDGCode(-2212);
			}
			else
			{
				std::cout << "Error - Encountered invalid particle type in entry " << j << ", will continue input" << std::endl;
				continue;
			}

			//Retrive momenta terms as doubles
			ThreeVector tv(f.getFieldAsDouble(3),f.getFieldAsDouble(4),f.getFieldAsDouble(5));
			particle[j].setThreeMomentum(tv);

			//Retrieve Data Source as string
			datasource[j] = f.getFieldAsString(6);
			
			//Check input
			if (f.inputFailed()) break;

			j++;

		}
	}
	
	//Find and read mu+ mu- particles in run4.dat
	std::cout << "mu+ and mu- particles observed in run4.dat:" << std::endl;
	std::cout << "Event, E    , p_x  , p_y  , p_z" << std::endl;  
	
	int mupsize(0);
	int mumsize(0);

	double mumass = 0.106;

	for (int j(0); j < size; j++ )
	{
		if ( (particle[j].getPDGCode() == 13 || particle[j].getPDGCode() == -13) && datasource[j] == "run4.dat") 
		{
			particle[j].setMass(mumass);
			ThreeVector tv = particle[j].getThreeMomentum();
			std::cout << eventnum[j] << " , " << particle[j].getEnergy() << ", " << tv.getX() << ", " << tv.getY() << ", " << tv.getZ() << std::endl;
		if ( particle[j].getPDGCode() == 13){ mumsize++;}
		if ( particle[j].getPDGCode() == -13){ mupsize++;}
		}
	
	}
	//Declare combined invariant mass array
	int combsize = mupsize * mumsize;

	FourVector combevents[combsize];
	double invarmass[combsize];
	int mueventnum[combsize][2];
	int mupairindex[combsize];

	for (int k(0);  k <combsize; k++)
	{
		mupairindex[k] = k + 1;
	}
	
	int l(0);
	for (int j = 0; j < size; j++ )
	{
		if ( particle[j].getPDGCode() == -13  && datasource[j] == "run4.dat") 
		{
			for (int k = 0; k < size; k++)
			{	
				if ( particle[k].getPDGCode() == 13  && datasource[k] == "run4.dat")
				{
					//Combine 4 momenta of each mu- mu+ pair
					combevents[l].setT(particle[k].getEnergy() + particle[j].getEnergy()) ;
					ThreeVector threemom1(particle[k].getThreeMomentum());
					ThreeVector threemom2(particle[j].getThreeMomentum());
					combevents[l].setX(threemom1.getX() + threemom2.getX());
					combevents[l].setY(threemom1.getY() + threemom2.getY());
					combevents[l].setZ(threemom1.getZ() + threemom2.getZ());

					//Calculate invariant mass of the pair
					invarmass[l] = sqrt(combevents[l].interval());

					//Record event numbers of the pair
					mueventnum[l][0] = eventnum[j];
					mueventnum[l][1] = eventnum[k];	

					l++;
				}
			}		
		}
	
	}
	
	bubblesort( invarmass, mupairindex, combsize);
		
	std::cout << "Largest 10 invariant mass combinations are: " << std::endl;
	for ( int k = 0; k < 10; k++ )
	{
		std::cout << "Invariant mass: " << invarmass[mupairindex[k]-1] << ", mu+ event: " << mueventnum[mupairindex[k]-1][0] << ", mu- event: " << mueventnum[mupairindex[k]-1][1] << std::endl; 
	}	

}

