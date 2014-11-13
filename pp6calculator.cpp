//pp6calculator - Author: Andrew Crocombe
//-------------------------------------------------------------------
#include <iostream>
#include <climits>
#include <cmath>

//Program Libraries
//-------------------------------------------------------------------
#include "PP6Math.hpp"
#include "PP6Menus.hpp"

//Main Program
//--------------------------------------------------------------------
int main()
{
	// Declare output and selection variables
	double out1(0),out2(0);	
	
	char menu;

	bool errorcheck;	
	
	//Check for user exiting program
	while ( menu != 'x')
	{	
		//Choose day 1 or day 2
		menu = toplevel();	

		//Break from loop on user input of x
		if ( menu == 'x' )
		{
			break;
		}
	
		//Choose day 1 operations
		else if ( menu == '1' )
		{
			char submenu;
			//Choose operations
			submenu = day1menu();

			//Break from menu on user input of x
			if ( submenu == 'x' )
			{
				break;
			}

			//Choose mathematical operations
			else if ( (submenu == '+') || (submenu == '-') || (submenu == '*') || (submenu == '/'))
			{	
				double a(0), b(0);
				//Print instructions
				std::cout << "Input numbers to be operated on in the form: (a) " << submenu << " (b) \n";

				//Ask for user input
				std::cout << "Input a and b in order \n";
				a = inputcheck();
				b = inputcheck();
	
				//Addition
				if ( submenu == '+' ) 
				{
					//Compute addition and output to user
					add(a, b, out1);
					print(submenu, out1);
				}
				//Subtraction
				else if ( submenu == '-' ) 
				{
					//Compute subtraction and output to user
					subtract(a, b, out1);
					print(submenu, out1);
				}
				//Multiplication
				else if ( submenu == '*' ) 
				{
					//Compute multiplication and output to user
					multiply(a, b, out1);
					print(submenu, out1);
				}

				//Division
				else if ( submenu == '/' ) 
				{

					errorcheck = divide(a, b, out1);
					if ( 0 == errorcheck)
					{
						print(submenu, out1);
					}
					else
					{
						std::cout << "Error in input, check that b is not equal to zero \n";
					}		
				}	
			}
		
			//Find the intercept of a straight line
			else if ( submenu == 'i' )
			{	
				double a(0), b(0);
				//Print instructions
				std::cout << "Input equation of the straight line in the form: (a)x + (b) \n";

			
				//Ask for user input
				std::cout << "Input a and b in order \n";
				a = inputcheck();
				b = inputcheck();
			
				//Compute and print the x intercept of a straight line
				errorcheck = intercept(a, b, out1);
				if ( 0 == errorcheck)
				{
					std::cout << "The x intercept of the straight line is: " << out1 << std::endl;
				}
				else
				{
					std::cout << "Error in input, check that a is not equal to zero \n";
				}


			}
			
			//Solve a quadratic equation
			else if ( submenu == 'q' )
			{
				double a(0), b(0), c(0);
				//Print instructions
				std::cout << "Input quadratic equation in the form: (a)x^2 + (b)x + (c) \n";
				
				//Ask for user input
				std::cout << "Input a, b and c in order \n";
				a = inputcheck();
				b = inputcheck();
				c = inputcheck();	

				errorcheck = quadratic(a, b, c, out1, out2);

				if ( errorcheck == 0 )
				{		
					std:: cout << "The two solutions to the quadratic equation are: " << out1 << " and " << out2 << std::endl;
				}
				
				else
				{
					std::cout << "No real solutions to the quadratic equation \n";
				}

			}
			
			//Find the length of a three vector
			else if ( submenu == '3' )
			{
				double a(0), b(0), c(0);
				//Print instructions
				std::cout << "Input the 3 vector in the order ((x1), (x2), (x3)) \n";
				
				//Ask for user input
				a = inputcheck();	
				b = inputcheck();
				c = inputcheck();
				
				threevector(a, b, c, out1);
				std::cout << "The length of the three vector is: " << out1 << std::endl;

		
			}

			//Find the length of a four vector
			else if ( submenu == '4' )
			{
				double a(0), b(0), c(0), d(0);
				//Print instructions
				std::cout << "Input the 4 vector in the order ((x0), (x1), (x2), (x3)) \n";
				
				//Ask for user input			
				a = inputcheck();
				b = inputcheck();			
				c = inputcheck();
				d = inputcheck();	

				fourvector(a, b, c, d, out1);
				std::cout << "The length of the four vector is: " << out1 << std::endl;

			
			}

			//Find the invariant mass of two particles
			else if ( submenu == 'm' )
			{
				double a(0), b(0), c(0), d(0);
				//Print instructions
				std::cout << "Input the energy and momentum of the first particle in the order ((E), (p1), (p2), (p3)) \n";
				
				//Ask for user input
				a = inputcheck();
				b = inputcheck();			
				c = inputcheck();
				d = inputcheck();		
				
				//Check that energy is greater then total momentum for particle 1
				if ( (a * a) < ( (b * b) + (c * c) + (d * d) ))
				{
					std::cout << "Particles total momentum cannot be greater then its total energy, check values and re-enter \n";
					continue;
				}
				double e(0), f(0), g(0), h(0);
				//Print instructions
				std::cout << "Input the energy and momentum of the second particle in the order ((E), (p1), (p2), (p3)) \n";
				
				//Ask for user input
				e = inputcheck();
				f = inputcheck();			
				g = inputcheck();
				h = inputcheck();			
			
				//Check that energy is greater then total momentum for particle 1
				if ( (e * e) < ( (f * f) + (g * g) + (h * h) ))
				{
					std::cout << "Particles total momentum cannot be greater then its total energy, check values and re-enter \n";
					continue;
				}
			
				fourvector((a+e), (b+f), (c+g), (d+h), out1);
				std::cout << "The total invariant mass of the two particles is: " << out1 << std::endl;

			}
			else	
			{
				std::cout << "Invalid choice of operation \n";
			}
		}	
		else if ( menu == '2' )
		{
			char submenu;
			//Check for user choice of operation
			submenu = day2menu();

			//Break from menu on user input of x
			if ( submenu == 'x' )
			{
				break;
			}
			
			else if ( submenu == 'b' )
			{
				//Ask for user input
				std::cout << "Input size of array to be sorted \n";

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

				
				double array[size];

				//Input array values
				std::cout << "Input values of the array in order" << std::endl;
				for ( int k = 0; k < size; k++ )
				{
					array[k] = inputcheck();
				}
				
				//Sort the numbers and print 
				bubblesort(array, size);
				std::cout << "Sorted array is" << std::endl;
				for ( int k = 0; k < size; k++ )
				{
					std::cout << array[k] << "\n";
				}	
					
			}
			else	
			{
				std::cout << "Invalid choice of operation \n";
			}
	
		}
		
		//Check for invalid choice of operation
		else	
		{
			std::cout << "Invalid choice of operation \n";
		}
	}
	return 0;
}

