#include <iostream>
#include <climits>
#include <cmath>

#include "FourVectorAnalysis.hpp"
#include "PP6Math.hpp"

//Definition for four vector boost
 boost_z( double &t, double &x, double &y, double &z, double v)
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

		t = gamma * ( t - (v * z));
		x = x;
		y = y;
		z = gamma * ( z - (v * t));
	
		return 0;
	}
}
//Calculate the interval of a four vector
int interval( double t, double x, double y, double z, double& interval)
{
        if ( (t * t) > ( (x * x) + (y * y) + (z * z) ) )
	{
		interval = sqrt (( (t * t) - ( (x * x) + (y * y) + (z * z)) )  );
		return 0;
	}
	else { return 1;}
}
