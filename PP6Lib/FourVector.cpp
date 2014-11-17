#include <iostream>
#include <climits>
#include <cmath>

#include "FourVector.hpp"

//Definitions for FourVector constructors
FourVector::FourVector(const double t_, const double x_, const double y_, const double z_) : t(t_), x(x_), y(y_), z(z_), s(0)
{
	intervalFourVector();
}

FourVector::FourVector(const FourVector& other) : t(other.t), x(other.x), y(other.y), z(other.z), s(other.s)
{}

//Definition for four-vector boost
int FourVector::boostFourVector(const double v)
{
	if ( v == 0 )
	{
		return 1;	
	}
	
	else if ( (v > 1) || (v < -1) )
	{
		return 2;
	}

	else 
	{	
		double gamma(0);

		gamma = ( 1 / sqrt(( 1 - (v * v) )));

		t = gamma * (t - (v * z));
		x = x;
		y = y;
		z = gamma * (z - (v * t));
	
		return 0;
	}
}

//Calculate the interval of a four-vector
void FourVector::intervalFourVector() 
{
        s = (t * t) - ( (x * x) + (y * y) + (z * z));
}
