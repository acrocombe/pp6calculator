//PP6Day3 file - Day 3 functionality for the pp6calculator program
//-------------------------------------------------------------------
#include "PP6Math.hpp"
#include "PP6Day3.hpp"
#include "FourVector.hpp"
#include "FileReader.hpp"

#include <iostream>
#include <climits>
#include <cmath>
#include <cstring>

//Definition for PP6Day3 function
void Day3(char submenu)
{ 
	//Functionality to boost a 4 vector
	if ( submenu == 'b' )
	{
		double x(0), y(0), z(0), t(0), v(0);
		
		//Ask for user input of the 4 vector to be lorenzt boosted
		std::cout << "Input the components of the 4-vector in natural units (t, x, y, z) and the speed along the boosted axes, v (in units of c), in that order" << std::endl;
		
		t = inputcheck();
		x = inputcheck();
		y = inputcheck();
		z = inputcheck();
		v = inputcheck();
		
		FourVector::fv(t, x, y, z);

		/*FourVector *fv;
		fv = createFourVector();

		setFourVector ( fv, t, x, y, z);
		
		int boost = boost_z( fv, v);

		getFourVector ( fv, t, x, y, z);

		if ( boost == 1 )
		{
			std::cout << "Frame is not moving at a relative speed, 4-vector is not boosted (unchanged from input)" << std::endl;
		}
		else if ( boost == 2 )	
		{
			std::cout << "Speed is greater then c, please enter v in units of c" << std::endl;

		}
		else if ( boost == 0 )
		{
			std::cout << "Boosted 4-vector is:" << std::endl;
			std::cout << "t: " << t << ", x: " << x << ", y: " << y << ", z: " << z << std::endl;
		}

		destroyFourVector(fv);*/
	}

	//Functionality to calculate interval of a 4-vector

}
		


