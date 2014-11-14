//pp6calculator - Author: Andrew Crocombe
//-------------------------------------------------------------------
#include <iostream>
#include <climits>
#include <cmath>

//Program Libraries
//-------------------------------------------------------------------
#include "PP6Math.hpp"
#include "PP6Menus.hpp"
#include "PP6Day1.hpp"
#include "PP6Day2.hpp"

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
		if ( menu == '1' )
		{
			while (true)
			{
				char submenu;
				//Choose operations
				submenu = day1menu();
				
				if (submenu == 'x')
				{
					break;
				}
				
				Day1(submenu);
			}
		}	
		else if ( menu == '2' )
		{
			while (true)
			{
				char submenu;
				//Check for user choice of operation
				submenu = day2menu();

				//Break from menu on user input of x
				if ( submenu == 'x' )
				{
					break;
				}
				Day2(submenu);
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

