#include <iostream>
int main()
{
	// Declare variables to be multiplied as well as output
	
	double a(0);
	double b(0);
	double c(0);
	
	//Ask for user input
	std::cout << "Input first number \n";
	std::cin >> a;

	std::cout << "Input second number \n";
	std::cin >> b;

	//Compute product
	c = a * b;

	//Output product to user
	std::cout << "Product of two numbers is: ";
	std::cout << c <<std::endl;

	return 0;
}
