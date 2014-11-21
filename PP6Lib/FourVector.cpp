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

void FourVector::setT(double t_)
{
	t = t_;
	intervalFourVector();
}

void FourVector::setX(double x_)
{
	x = x_;
	intervalFourVector();
}

void FourVector::setY(double y_)
{
	y = y_;
	intervalFourVector();
}

void FourVector::setZ(double z_)
{
	z = z_;
	intervalFourVector();
}

//Definition for four-vector boost
int FourVector::boost_z(const double v)
{
	if ( v == 0 )
	{
		return 1;	
	}
	
	else if ( (v >= 1) || (v <= -1) )
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

//Definitions for operator overloads
FourVector& FourVector::operator+=(const FourVector& rhs)
{
	t += rhs.t;
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	intervalFourVector();
	return *this;
}

FourVector& FourVector::operator-=(const FourVector& rhs)
{
	t -= rhs.t;
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	intervalFourVector();
	return *this;
}

FourVector& FourVector::operator*=(const double rhs)
{
	t *= rhs;
	x *= rhs;
	y *= rhs;
	z *= rhs;
	intervalFourVector();
	return *this;
}

FourVector& FourVector::operator/=(const double rhs)
{
	t /= rhs;
	x /= rhs;
	y /= rhs;
	z /= rhs;
	intervalFourVector();
	return *this;
}

FourVector& FourVector::operator=(const FourVector& rhs)
{
	if (&rhs != this)
	{
		t = rhs.t;
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		intervalFourVector();
	}
	return *this;
}


//Calculate the interval of a four-vector
void FourVector::intervalFourVector() 
{
        s = (t * t) - ( (x * x) + (y * y) + (z * z));
}

//Free operators for the FourVector class
FourVector operator+(const FourVector& lhs, const FourVector& rhs)
{
	FourVector temp(lhs);
	temp += rhs;
	return temp;
}

FourVector operator-(const FourVector& lhs, const FourVector& rhs)
{
	FourVector temp(lhs);
	temp -= rhs;
	return temp;
}

std::istream& operator>>(std::istream& stream, FourVector& fv)
{
	double t, x, y, z;
	stream >> t >> x >> y >> z;
	fv.setT(t);
	fv.setX(x);
	fv.setY(y);
	fv.setZ(z);
	return stream;
}

std::ostream& operator<<(std::ostream& stream, const FourVector& fv)
{
	stream << "["<< fv.getT() << ", " << fv.getX() << ", " << fv.getY() << ", " << fv.getZ() << "]";
	return stream;
}


