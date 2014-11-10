#include <iostream>
#include <climits>
#include <cmath>

//Program Libraries
#include "PP6Math.hpp"

//Main Program
//-----------------------------------------------------------------
int main()
{
	// Declare variables to be multiplied as well as output
	double a(0);
	double b(0);
	double c(0);
	double d(0);
 	double e(0);
	double f(0);
	double g(0);
	double h(0);

	double out1(0);
	double out2(0);	
	
	char function;

	bool errorcheck;	
	
	//Check for user exiting program
	while ( function != 'x')
	{	
		//Ask user for choice of operation
		std::cout << "Choose the function to be carried out (use x to exit program) \nUse +, -, * or / to carry out mathematical functions \nUse i to find the intercept of a line on the x-axis \nUse q to find the solutions to a quadratic equation \nUse 3 or 4 to find the length of a three or four vector\nUse m to find the invariant mass of two particles \n ";
		std::cin >> function;
		
		//Check for invalid input of function
		if (inputcheck() == false)
		{
			continue;
		}

		//Break from loop on user input of x
		if ( function == 'x' )
		{
			break;
		}
			
		else if ( function == 's' )
		{
			//Ask for user input
			std::cout << "Input size of array to be sorted \n";

			int size(0);

			std::cin >> size;

			//Check for invalid input	
			if (inputcheck() == false)
			{
				continue;
			}

			
			double array[size];

			//Input array values
			std::cout << "Input values of the array in order" << std::endl;
			for ( int k = 0; k < size; k++ )
			{
				std::cin >> array[k];
				if (inputcheck() == false)
				{
					continue;
				}

			}
			
			//Sort the numbers and print 
			bubblesort(array, size);
			std::cout << "Sorted array is" << std::endl;
			for ( int k = 0; k < size; k++ )
			{
				std::cout << array[k] << "\n";
			}	
				
		}

		else if ( (function == '+') || (function == '-') || (function == '*') || (function == '/'))
		{	
			//Print instructions
			std::cout << "Input numbers to be operated on in the form: (a) " << function << " (b) \n";

			//Ask for user input
			std::cout << "Input a and b in order \n";
			std::cin >> a >> b;
			

			//Check for invalid input
			if (inputcheck() == false)
				{
					continue;
				}

			//Addition
			if ( function == '+' ) 
			{
				//Compute addition and output to user
				add(a, b, out1);
				print(function, out1);
			}
			//Subtraction
			else if ( function == '-' ) 
			{
				//Compute subtraction and output to user
				subtract(a, b, out1);
				print(function, out1);
			}
			//Multiplication
			else if ( function == '*' ) 
			{
				//Compute multiplication and output to user
				multiply(a, b, out1);
				print(function, out1);
			}

			//Division
			else if ( function == '/' ) 
			{

				errorcheck = divide(a, b, out1);
				if ( 0 == errorcheck)
				{
					print(function, out1);
				}
				else
				{
					std::cout << "Error in input, check that b is not equal to zero \n";
				}		
			}	
		}
		
		//Find the intercept of a straight line
		else if ( function == 'i' )
		{

			//Print instructions
			std::cout << "Input equation of the straight line in the form: (a)x + (b) \n";

		
			//Ask for user input
			std::cout << "Input a and b in order \n";
			std::cin >> a >> b;
			

			//Check for invalid input

			if (inputcheck() == false)
			{
				continue;
			}
		
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
		else if ( function == 'q' )
		{

			//Print instructions
			std::cout << "Input quadratic equation in the form: (a)x^2 + (b)x + (c) \n";
			
			//Ask for user input
			std::cout << "Input a, b and c in order \n";
			std::cin >> a >> b >> c;
			
			//Check for invalid input
			if (inputcheck() == false)
			{
				continue;
			}

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
		else if ( function == '3' )
		{
			//Print instructions
			std::cout << "Input the 3 vector in the order ((x1), (x2), (x3)) \n";
			
			//Ask for user input
			std::cin >> a >> b >> c;
			

			//Check for invalid input 
			if (inputcheck() == false)
			{
				continue;
			}
			
			threevector(a, b, c, out1);
			std::cout << "The length of the three vector is: " << out1 << std::endl;

	
		}

		//Find the length of a four vector
		else if ( function == '4' )
		{
			//Print instructions
			std::cout << "Input the 4 vector in the order ((x0), (x1), (x2), (x3)) \n";
			
			//Ask for user input
			std::cin >> a >> b >> c >> d;			
			

			//Check for invalid input 
			if (inputcheck() == false)
			{
				continue;
			}

			fourvector(a, b, c, d, out1);
			std::cout << "The length of the four vector is: " << out1 << std::endl;

		
		}

		//Find the invariant mass of two particles
		else if ( function == 'm' )
		{
			
			//Print instructions
			std::cout << "Input the energy and momentum of the first particle in the order ((E), (p1), (p2), (p3)) \n";
			
			//Ask for user input
			std::cin >> a >> b >> c >> d;
			

			//Check for invalid input
			if (inputcheck() == false)
			{
				continue;
			}
			
			//Check that energy is greater then total momentum for particle 1
			if ( (a * a) < ( (b * b) + (c * c) + (d * d) ))
			{
				std::cout << "Particles total momentum cannot be greater then its total energy, check values and re-enter \n";
				continue;
			}

			//Print instructions
			std::cout << "Input the energy and momentum of the second particle in the order ((E), (p1), (p2), (p3)) \n";
			
			//Ask for user input
			std::cin >> e >> f >> g >> h;
			

			//Check for invalid input
			if (inputcheck() == false)
			{
				continue;
			}
		
			//Check that energy is greater then total momentum for particle 1
			if ( (e * e) < ( (f * f) + (g * g) + (h * h) ))
			{
				std::cout << "Particles total momentum cannot be greater then its total energy, check values and re-enter \n";
				continue;
			}
		
			fourvector((a+e), (b+f), (c+g), (d+h), out1);
			std::cout << "The total invariant mass of the two particles is: " << out1 << std::endl;

		}
		
		//Check for invalid choice of operation
		else	
		{
			std::cout << "Invalid choice of operation \n";
		}
	}
	return 0;
}

