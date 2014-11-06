#include <iostream>
#include <climits>

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

int main()
{
	// Declare variables to be multiplied as well as output
	double num1(0);
	double num2(0);
	double out(0);
	
	char function;	
	
	//Check for user exiting program
	while ( function != 'q')
	{	
		
		//Ask user for choice of operation
		std::cout << "Choose the operation to be carried out (+, -, *, / or use q to exit program) \n";
		std::cin >> function;
		
		//Check for invalid input of function
		if (!std::cin)
		{
			std::cerr << "[error] Error in input" << std::endl;
			//Clear buffer to reset for next loop

			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			continue;		
		}

		//Break from loop on user input of q
		else if ( function == 'q' )
		{
			break;
		}
		
		//Ask for user input
		std::cout << "Input first number \n";
		std::cin >> num1;
		

		//Check for invalid input of num1
		if (!std::cin)
		{
			std::cerr << "[error] Error in input" << std::endl;
			//Clear buffer to reset for next loop

			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			continue;		
		}

	
		std::cout << "Input second number \n";
		std::cin >> num2;
		

		//Check for invalid input of num2
		if (!std::cin)
		{
			std::cerr << "[error] Error in input" << std::endl;
			//Clear buffer to reset for next loop

			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			continue;		
		}


		//Addition
		if ( function == '+' ) 
		{
			//Compute addition
			out = add(num1, num2);

			//Output addition to user
			std::cout << "Addition of two numbers is: ";
			std::cout << out <<std::endl;
		}
		//Subtraction
		else if ( function == '-' ) 
		{
			//Compute subtraction
			out = subtract(num1, num2);

			//Output subtraction to user
			std::cout << "Subtraction of two numbers is: ";
			std::cout << out <<std::endl;
		}
		//Multiplication
		else if ( function == '*' ) 
		{
			//Compute product
			out = multiply(num1, num2);

			//Output product to user
			std::cout << "Product of two numbers is: ";
			std::cout << out <<std::endl;
		}

		//Division
		else if ( function == '/' ) 
		{
			//Check for dividing by zero
			if ( 0 == num2 )
			{
				std::cout << "Cannot divide by zero, please enter a non zero second number \n";
			}


			else
			{
				//Compute division
				out = divide(num1, num2);
			
				//Output division to user
				std::cout << "Division of two numbers is: ";
				std::cout << out <<std::endl;
			}
		}
		
		//Check for invalid choice of operation
		else	
		{
			std::cout << "Invalid choice of operation, please enter +, -, *, / or q \n";
		}
	}
	return 0;
}
