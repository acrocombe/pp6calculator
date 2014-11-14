//PP6Day2 file - Day 2 functionality for the pp6calculator program
//-------------------------------------------------------------------
#include "PP6Math.hpp"
#include "PP6Day2.hpp"
#include "FileReader.hpp"

#include <iostream>
#include <climits>
#include <cmath>
#include <cstring>

//Definition for PP6Day2 function

void Day2(char submenu)
{
	if ( submenu == 'b' )
	{
		//Ask for user input
		std::cout << "Input size of array to be sorted " << std::endl;

		int size(0);

		std::cin >> size;

		//Check for invalid input	
		while (!std::cin)
		{
			std::cerr << "Error in input of array size"  << std::endl;
			//Clear buffer to reset for next loop
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');

			std::cin >> size;
		}
		
		double array[size];
		double location[size];

		for (int k = 0; k < size; k++)
		{
			location[k] = k+1;
		}

		//Input array values
		std::cout << "Input values of the array in order" << std::endl;
		for ( int k = 0; k < size; k++ )
		{
			array[k] = inputcheck();
		}
		
		//Sort the numbers and print 
		bubblesort(array, location, size);
		std::cout << "Sorted array is:" << std::endl;
		for ( int k = 0; k < size; k++ )
		{
			std::cout << array[k] << "\n";
		}	
		std::cout << "Sorted array by original index location is:" << std::endl;
		for ( int k = 0; k < size; k++ )
		{
			std::cout << location[k] << "\n";
		}
			
	}
	if ( submenu == 'g' )
	{
		//Ask for user input
		std::cout << "Input number of events to be generated" << std::endl;

		int size(0);

		std::cin >> size;

		//Check for invalid input	
		while (!std::cin)
		{
			std::cerr << "Error in input of the operation" << std::endl;
			//Clear buffer to reset for next loop
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');

			std::cin >> size;
		}
		
		double array[size][4];
		double mean(0);
		double sd(0);

		generate(array, size, mean, sd);

		//Ask if user wants generated events to be printed
		std::cout << "Do you wish to view the generated events? (y/n)" << std::endl;
		
		char view('\0');

		std::cin >> view;
			
		//Check for invalid input	
		while (!std::cin)
		{
			std::cerr << "Error in input" << std::endl;
			//Clear buffer to reset for next loop
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');

			std::cin >> view;
		}

		if ( view == 'y' )
		{
			std::cout << "Generated events are:\n   E      , px, py, pz " <<std::endl;
			for ( int j=0; j < size; ++j )
			{
				std::cout << (j+1) << ") " << array[j][0] <<", " << array[j][1] << ", " << array[j][2] << ", " << array[j][3] << std::endl; 
			}
		}		
	
		//Print mean and standard deviation
		std::cout << "The mean energy of the generated events is: " << mean << std::endl;
		std::cout << "The standard deviation of the generated events is: " << sd << std::endl;
	}

	if ( submenu == 'a' )
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
		int size = 1;
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

		std::string particle[size];
		std::string datasource[size];
		
		FileReader f(file);

		int eventnum[size];

		double p[size][3];

		//Check that file is valid
		if (f.isValid())
		{
			f.nextLine();
			int j = 0;
			while (f.nextLine())
			{
				//Retrieve event number as integer
				eventnum[j] = f.getFieldAsDouble(1);

				//Retrieve particle name as string
				particle[j] = f.getFieldAsString(2);

				//Retrive momenta terms as doubles
				p[j][0] = f.getFieldAsDouble(3);
				p[j][1] = f.getFieldAsDouble(4);
				p[j][2] = f.getFieldAsDouble(5);

				//Retrieve Data Source as string
				datasource[j] = f.getFieldAsString(6);
				
				//Check input
				if (f.inputFailed()) break;

				j++;

			}
		}
		
		//Find and read mu+ mu- particles in run4.dat
		std::cout << "mu+ and mu- particles observed in run4.dat:" << std::endl;
		std::cout << "Event, p_x  , p_y  , p_z" << std::endl;  
		
		int mupsize(0);
		int mumsize(0);

		for (int j = 0; j < size; j++ )
		{
			if ( (particle[j] == "mu+" || particle[j] == "mu-") && datasource[j] == "run4.dat") 
			{
				std::cout << eventnum[j] << " , " << p[j][0] << ", " << p[j][1] << ", " << p[j][2] << std::endl;
			if ( particle[j] == "mu-"){ mumsize++;}
			if ( particle[j] == "mu+"){ mupsize++;}
			}
		
		}
		//Declare combined invariant mass array
		int combsize = mupsize * mumsize;

		double combevents[combsize][5];
		double mueventnum[combsize][2];
		
		double mumass = 0.106;

		int l(0);
		for (int j = 0; j < size; j++ )
		{
			if ( particle[j] == "mu+"  && datasource[j] == "run4.dat") 
			{
				for (int k = 0; k < size; k++)
				{	
					if ( particle[k] == "mu-"  && datasource[k] == "run4.dat")
					{
						//Combine 4 momenta of each mu- mu+ pair
						combevents[l][0] = energy(mumass, p[j][1], p[j][2], p[j][3]) + energy(mumass, p[k][1], p[k][2], p[k][3]); 
						combevents[l][1] = p[j][1] + p[k][1];
						combevents[l][2] = p[j][2] + p[k][2];
						combevents[l][3] = p[j][3] + p[k][3];

						//Calculate invariant mass of the pair
						int calc = fourvector( combevents[l][0], combevents[l][1], combevents[l][2], combevents[l][3], combevents[l][4] );
						
						//Record event numbers of the pair
						mueventnum[l][0] = eventnum[j];
						mueventnum[l][1] = eventnum[k];	

						l++;
					}
				}		
			}
		
		}
		
		bubblesortmulti( combevents, mueventnum, combsize, 4);
			
		std::cout << "Largest 10 invariant mass combinations are: " << std::endl;
		for ( int k = 0; k < 10; k++ )
		{
			std::cout << "Invariant mass: " << combevents[k][4] << ", mu+ event: " << mueventnum[k][0] << ", mu- event: " << mueventnum[k][1] << std::endl; 
		}	

	}
	else	
	{
		std::cout << "Invalid choice of operation" <<std::endl;
	}
}

