#include <iostream>
#include <climits>
#include <cmath>

double add( double a, double b)
{
	return a + b;
}

double subtract( double a, double b)
{
	return a - b;
}

double multiply( double a, double b)
{
	return a * b;
}

double divide( double a, double b)
{
	return a / b;
}

//Calculates intercept of a line on the x-axis
double intercept( double a, double b)
{
	return (- b) / a;
}

//Solves a quadratic equation with a positive square root, positive solution
double quadraticp( double a, double b, double c)
{
	return ( (-b) + sqrt((( b * b ) - ( 4 * a * c))))/( 2 * a);
}

//Solves a quadratic equation with a positive square root, negative solution
double quadraticm( double a, double b, double c)
{
	return ( (-b) - sqrt((( b * b ) - ( 4 * a * c))))/( 2 * a);
}

//Gives the real part of the solution of a quadratic with complex solutions
double compquadreal( double a, double b)
{
	return ( (-b) / (2 * a));
}

//Give the positive imaginary part of the solution of a quadratic with complex solutions
double compquadim( double a, double b, double c)
{
	return (sqrt(-( ( b * b ) - ( 4 * a * c ) ))/( 2 * a ) );
}

//Calculates length of a 3 vector
double threevector( double a, double b, double c)
{
	return sqrt ( (a * a) + (b * b) + (c * c));
}

//Calculates length of a 4 vector
double fourvector( double a, double b, double c, double d)
{
	return sqrt (std::abs( (a * a) -( (b * b) + (c * c) + (d * d) ) ));
}

void print(char a, double b)
{
	std::cout << "Result of " << a <<" operation is: " << b << std::endl;
}	

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
	
	char function;	
	
	//Check for user exiting program
	while ( function != 'x')
	{	
		
		//Ask user for choice of operation
		std::cout << "Choose the function to be carried out (use x to exit program) \nUse +, -, * or / to carry out mathematical functions \nUse i to find the intercept of a line on the x-axis \nUse q to find the solutions to a quadratic equation \nUse 3 or 4 to find the length of a three or four vector\nUse m to find the invariant mass of two particles\n ";
		std::cin >> function;
		
		//Check for invalid input of function
		if (!std::cin)
		{
			std::cerr << "Error in input of operation" << std::endl;
			//Clear buffer to reset for next loop

			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			continue;		
		}

		//Break from loop on user input of x
		if ( function == 'x' )
		{
			break;
		}
		
		if ( (function == '+') || (function == '-') || (function == '*') || (function == '/'))
		{	
			//Print instructions
			std::cout << "Input numbers to be operated on in the form: (a) " << function << " (b) \n";

			//Ask for user input
			std::cout << "Input a and b in order \n";
			std::cin >> a >> b;
			

			//Check for invalid input
			if (!std::cin)
			{
				std::cerr << "Error in input of number" << std::endl;
				//Clear buffer to reset for next loop

				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				continue;		
			}

			//Addition
			if ( function == '+' ) 
			{
				//Compute addition and output to user
				print(function, add(a, b));
			}
			//Subtraction
			else if ( function == '-' ) 
			{
				//Compute subtraction and output to user
				print(function, subtract(a, b));
			}
			//Multiplication
			else if ( function == '*' ) 
			{
				//Compute multiplication and output to user
				print(function, multiply(a, b));
			}

			//Division
			else if ( function == '/' ) 
			{
				//Check for dividing by zero
				if ( 0 == b )
				{
					std::cout << "Cannot divide by zero, please enter a non zero second number \n";
				}


				else
				{
					//Compute division and output to user
					print(function, divide(a, b));	
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
			if (!std::cin)
			{
				std::cerr << "Error in input of number" << std::endl;
				//Clear buffer to reset for next loop

				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				continue;		
			}

			//Print the x intercept of a straight line
			std::cout << "The x intercept of the straight line is: " << intercept(a, b) << std::endl;


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
			if (!std::cin)
			{
				std::cerr << "Error in input of number" << std::endl;
				//Clear buffer to reset for next loop

				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				continue;		
			}

			if ( (( b * b ) - ( 4 * a * c ) ) < 0 )
			{
				std:: cout << "The two solutions to the quadratic equation are: " << compquadreal(a, b) << " +- " << compquadim(a, b, c) << "i \n";
			}
			
			else
			{
				std::cout << "The two solutions to the quadratic equation are: " << quadraticp(a, b, c) << " and " << quadraticm(a, b, c) << std::endl;
			}

		}
		
		//Find the length of a three vector
		else if ( function == '3' )
		{
			//Print instructions
			std::cout << "Input the 3 vector in the order ((x1), (x2), (x3)) \n";
			
			//Ask for user input
			std::cin >> a;
			

			//Check for invalid input 
			if (!std::cin)
			{
				std::cerr << "Error in input of number" << std::endl;
				//Clear buffer to reset for next loop

				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				continue;		
			}
		
			std::cout << "The length of the three vector is: " << threevector(a, b, c) << std::endl;

	
		}

		//Find the length of a four vector
		else if ( function == '4' )
		{
			//Print instructions
			std::cout << "Input the 4 vector in the order ((x0), (x1), (x2), (x3)) \n";
			
			//Ask for user input
			std::cin >> a >> b >> c >> d;
			

			//Check for invalid input 
			if (!std::cin)
			{
				std::cerr << "Error in input of number" << std::endl;
				//Clear buffer to reset for next loop

				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				continue;		
			}
			std::cout << "The length of the four vector is: " << fourvector(a, b, c, d) << std::endl;

		
		}

		//Find the invariant mass of two particles
		else if ( function == 'm' )
		{
			
			//Print instructions
			std::cout << "Input the energy and momentum of the first particle in the order ((E), (p1), (p2), (p3)) \n";
			
			//Ask for user input
			std::cin >> a >> b >> c >> d;
			

			//Check for invalid input
			if (!std::cin)
			{
				std::cerr << "Error in input of number" << std::endl;
				//Clear buffer to reset for next loop

				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
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
			if (!std::cin)
			{
				std::cerr << "Error in input of number" << std::endl;
				//Clear buffer to reset for next loop

				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				continue;		
			}

			//Check that energy is greater then total momentum for particle 1
			if ( (e * e) < ( (f * f) + (g * g) + (h * h) ))
			{
				std::cout << "Particles total momentum cannot be greater then its total energy, check values and re-enter \n";
				continue;
			}

			std::cout << "The total invariant mass of the two particles is: " << fourvector((a+e), (b+f), (c+g), (d+h)) << std::endl;

		}
		
		//Check for invalid choice of operation
		else	
		{
			std::cout << "Invalid choice of operation, please enter +, -, *, / or q \n";
		}
	}
	return 0;
}
