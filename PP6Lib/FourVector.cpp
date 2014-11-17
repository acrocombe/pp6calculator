#include <iostream>
#include <climits>
#include <cmath>

#include "FourVector.hpp"

//Define a four-vector struct
struct FourVector {double t; double x; double y; double z;};

//Creator and destroyer function for the FourVector
FourVector* createFourVector()
{
	return new FourVector;
}

void destroyFourVector( FourVector *&fv )
{
	if (fv)
	{ 
		delete fv;
		fv = 0;
	}
}

//Set the values of the four-vector
void setFourVector( FourVector *fv, double t, double x, double y, double z)
{
	if (fv)
	{
		fv->t = t;
		fv->x = x;
		fv->y = y;
		fv->z = z;
	}	
}

//Retrieve the values of a four-vector
void getFourVector ( FourVector *fv, double& t, double& x, double&y, double& z)
{
	if (fv)
	{
		t = fv-> t;
		x = fv-> x;
		y = fv-> y;
		z = fv-> z;
	}
}

//Definition for four-vector boost
int boost_z( FourVector *fv, double v)
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

		fv->t = gamma * (fv->t - (v * fv->z));
		fv->x = fv->x;
		fv->y = fv->y;
		fv->z = gamma * ( fv->z - (v * fv->t));
	
		return 0;
	}
}

//Calculate the interval of a four-vector
int interval( FourVector *fv, double& interval)
{
        if ( (fv->t * fv->t) > ( (fv->x * fv->x) + (fv->y * fv->y) + (fv->z * fv->z) ) )
	{
		interval = sqrt (( (fv->t * fv->t) - ( (fv->x * fv->x) + (fv->y * fv->y) + (fv->z * fv->z)) )  );
		return 0;
	}
	else 
	{ 
		return 1;
	}
}
