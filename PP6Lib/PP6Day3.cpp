//PP6Day3 file - Day 3 functionality for the pp6calculator program
//-------------------------------------------------------------------
#include "PP6Math.hpp"
#include "PP6Day3.hpp"
#include "PP6MuonAnalysis.hpp"
#include "FourVector.hpp"
#include "FileReader.hpp"

#include <iostream>
#include <climits>
#include <cmath>
#include <cstring>

//Definition for PP6Day3 function
FourVector inputFourVector()
{
	double t(0), x(0), y(0), z(0);
	
	//Ask for user input of the 4 vector to be lorenzt boosted
	std::cout << "Input the components of the 4-vector in natural units (t, x, y, z) in that order" << std::endl;

	t = inputcheck();
	x = inputcheck();
	y = inputcheck();
	z = inputcheck();
	
	ThreeVector tv = ThreeVector(x, y, z);

	return FourVector(t, tv);
}

void Day3(char submenu)
{ 
	//Functionality to boost a 4 vector
	if ( submenu == 'b' )
	{
		double t(0), x(0), y(0), z(0), v(0);

		FourVector fv = inputFourVector();

		//Ask for user input of the 4 vector to be lorenzt boosted
		std::cout << "Input the speed along the boosted axes, v (in units of c)" << std::endl;
		
		v = inputcheck();
		
		int boost = fv.boost_z(v);

		t = fv.getT();
		x = fv.getX();
		y = fv.getY();
		z = fv.getZ();

		if ( boost == 1 )
		{
			std::cout << "Frame is not moving at a relative speed, 4-vector is not boosted (unchanged from input)" << std::endl;
		}
		else if ( boost == 2 )	
	 	{
			std::cout << "Speed is greater than or equal to c, please enter v in units of c" << std::endl;

		}
		else if ( boost == 0 )
		{
			std::cout << "Boosted 4-vector is:" << std::endl;
			std::cout << "t: " << t << ", x: " << x << ", y: " << y << ", z: " << z << std::endl;
		}

	}

	//Functionality to calculate interval of a 4-vector
	if ( submenu == 'i')
	{ 
		double interval(0);

		FourVector fv = inputFourVector();

		interval = fv.interval();

		if (interval < 0 )
		{ 
			std::cout << "The 4-vector is time-like" << std::endl;
			std::cout << "The interval of the 4-vector is: " << interval*(-1) << std::endl;
		}
		else if ( interval > 0 )
		{
			std::cout << "The 4-vector is space-like" << std::endl;
			std::cout << "The interval of the 4-vector is: " << interval << std::endl;
		}
		else if ( interval == 0 )
		{
			std::cout << "The 4-vector is light-like and thus the interval is 0" << std::endl;
		}


	}

	//Choose the analysis program
	if ( submenu == 'a' )
	{
		muonAnalysis();
	}


}
		


