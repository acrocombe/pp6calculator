#include "PP6Menus.hpp"

#include <iostream>
#include <climits>

//Definitions for PP6Menus functions

char toplevel()
{
	char day('\0');
	
	// Ask user for choice of operations, partioned by day of the course implemented
	std::cout << "        --------pp6calculator--------        " << std::endl;
	std::cout << "    Please choose which operations to use    " << std::endl;
	std::cout << "Operations from Day 1 and Day 2 are available" << std::endl;
	std::cout << "       Enter as 1 or 2 (use x to exit)       " << std::endl;

	std::cin >> day;

	//Check for invalid input of function
	while (!std::cin)
	{
		std::cerr << "Error in input of day requested" << std::endl;
		//Clear buffer to reset for next loop
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');

		std::cin >> day;
	}
	return day;

}

char day1menu()
{
	char function1('\0');

	//Ask user for choice of day 1 operations
	std::cout << "\n\n\n             --------Day 1 Operations--------             " << std::endl;
	std::cout << "   Choose the function to be carried out (use x to exit)   " << std::endl;
	std::cout << "       Enter +, -, * or / for mathematical operators       " << std::endl;
	std::cout << "   Enter i to find the intercept of a line on the x-axis   " << std::endl;
	std::cout << " Enter q to find the real solutions of a quadratic equation " << std::endl;
	std::cout << " Enter 3 or 4 to find the length of a three or four vector " << std::endl;
	std::cout << "    Enter m to find the invariant mass of two particles    " << std::endl;

	std::cin >> function1;

	//Check for invalid input of function
	while (!std::cin)
	{
		std::cerr << "Error in input of the operation" << std::endl;
		//Clear buffer to reset for next loop
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');

		std::cin >> function1;
	}
	return function1;
}

char day2menu()
{
	char function2('\0');

	//Ask user for choice of day 2 operations
	std::cout << "\n\n\n             --------Day 2 Operations--------             " << std::endl;
	std::cout << "   Choose the function to be carried out (use x to exit)   " << std::endl;
	std::cout << "              Enter b to bubble sort an array              " << std::endl;

	std::cin >> function2;

	//Check for invalid input of function
	while (!std::cin)
	{
		std::cerr << "Error in input of the operation" << std::endl;
		//Clear buffer to reset for next loop
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');

		std::cin >> function2;
	}
	return function2;
	
}
