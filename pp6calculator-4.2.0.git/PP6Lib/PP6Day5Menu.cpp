#include "PP6Day5Menu.hpp"

// Standard Library
#include <iostream>
#include <climits>
#include <vector>

// Third party
#include "FileReader.hpp"

// This Project
#include "PP6Math.hpp"
#include "PP6Particle.hpp"
#include "PP6ParticleInfo.hpp"
#include "PP6Cut.hpp"
#include "PP6MassCut.hpp"
#include "PP6EnergyCut.hpp"
#include "PP6MomentumCut.hpp"

void pp6day5_menu()
{

	char function('\0');
	
	while (true)
	{	
		//Ask for choice of operations
		std::cout << "\n        --------Day 5 Operations--------             " << std::endl;
		std::cout << "Choose the function to be carried out (use x to exit)   " << std::endl;
		std::cout << "Enter m to to apply a mass cut of greater than 0.4 GeV/c^2 to a set of particles   " << std::endl;
 		std::cout << "Enter e to to apply a energy cut in the range 2.0 GeV to 2.5 Gev to a set of particles   " << std::endl; 
		std::cout << "Enter p to to apply a momentum (magnitude) cut of less than 2.25 GeV/c to a set of particles   " << std::endl;	
		std::cin >> function;

		if ( function == 'x' )
		{
			break;
		}

		else if ( function == 'm' )
		{
			std::vector<Particle> particleSet;

			std::string file;

			//Ask for user input of file
			std::cout << "Input name of file to be analysed" << std::endl;
			std::cin >> file;

			while (!std::cin)
			{
				std::cerr << "Error in input of file name" << std::endl;
				//Clear buffer to reset for next loop
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
			
				std::cin >> file;
			}
			
			FileReader source(file);

			if (source.isValid())
			{
				source.nextLine();
				while (source.nextLine())
				{
					Particle input = source.getLine<Particle>();
					particleSet.push_back(input);
				}
		
			}

			MassCut masscut('>',0.4);
			std::vector<Particle> reduceSet(masscut.select(particleSet));

			size_t nParticles = reduceSet.size();
			
			std::cout << "Particles that pass cut: " << std::endl;
		
			for (size_t i(0); i < nParticles; ++i)
			{
				std::cout << reduceSet.at(i) << std::endl;
			}
		}

                else if ( function == 'e' )
                {
                        std::vector<Particle> particleSet;

                        std::string file;
			//Ask for user input of file
                        std::cout << "Input name of file to be analysed" << std::endl;
                        std::cin >> file;

                        while (!std::cin)
                        {
                                std::cerr << "Error in input of file name" << std::endl;
                                //Clear buffer to reset for next loop
                                std::cin.clear();
                                std::cin.ignore(INT_MAX, '\n');

                                std::cin >> file;
                        }

                        FileReader source(file);

                        if (source.isValid())
                        {
                                source.nextLine();
                                while (source.nextLine())
                                {
                                        Particle input = source.getLine<Particle>();
                                        particleSet.push_back(input);
                                }

                        }

                        EnergyCut energycut('r',2.0,2.5);
                        std::vector<Particle> reduceSet(energycut.select(particleSet));

                        size_t nParticles = reduceSet.size();

                        std::cout << "Particles that pass cut: " << std::endl;

                        for (size_t i(0); i < nParticles; ++i)
                        {
                                std::cout << reduceSet.at(i) << std::endl;
                        }
                }

                else if ( function == 'p' )
                {
                        std::vector<Particle> particleSet;

                        std::string file;
                        //Ask for user input of file
                        std::cout << "Input name of file to be analysed" << std::endl;
                        std::cin >> file;

                        while (!std::cin)
                        {
                                std::cerr << "Error in input of file name" << std::endl;
                                                 		
                                //Clear buffer to reset for next loop
                                std::cin.clear();
                                std::cin.ignore(INT_MAX, '\n');

                                std::cin >> file;
                        }

                        FileReader source(file);

                        if (source.isValid())
                        {
                                source.nextLine();
                                while (source.nextLine())
                                {
                                        Particle input = source.getLine<Particle>();
                                        particleSet.push_back(input);
                                }

                        }

                        MomentumCut momentumcut('<',2.25);
                        std::vector<Particle> reduceSet(momentumcut.select(particleSet));

                        size_t nParticles = reduceSet.size();

                        std::cout << "Particles that pass cut: " << std::endl;

                        for (size_t i(0); i < nParticles; ++i)
                        {
                                std::cout << reduceSet.at(i) << std::endl;
                        }
	
		}        


		else
		{
			std::cerr << "[error] Operation '" << function << "' not recognised." << std::endl;
			continue;
		}

	}

} 
