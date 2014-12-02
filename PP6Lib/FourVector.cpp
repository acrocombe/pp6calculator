#include <iostream>
#include <climits>
#include <cmath>

#include "FourVector.hpp"
#include "ThreeVector.hpp"

//Definitions for FourVector constructors
FourVector::FourVector(const double t_, const ThreeVector& x_) : t(t_), x(x_), s(0)
{
	intervalFourVector();
}

FourVector::FourVector(const FourVector& other) : t(other.t), x(other.x), s(other.s)
{}

void FourVector::setT(const double t_)
{
	t = t_;
	intervalFourVector();
}

void FourVector::setX(const double x_)
{
	x.setX(x_);
	intervalFourVector();
}

void FourVector::setY(const double y_)
{
	x.setY(y_);
	intervalFourVector();
}

void FourVector::setZ(const double z_)
{
	x.setZ(z_);
	intervalFourVector();
}

void FourVector::setThreeVector(const ThreeVector& threevec_)
{
	x = threevec_;
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
		double x1 = x.getX();
		double x2 = x.getY();
		double x3 = x.getZ();

		gamma = ( 1 / sqrt(( 1 - (v * v) )));

		t = gamma * (t - (v * x3));
		x1 = x1;
		x2 = x2;
		x3 = gamma * (x3 - (v * t));

		x.setX(x1), x.setY(x2), x.setZ(x3);
		intervalFourVector();
		return 0;
	}
}

//Definitions for operator overloads
FourVector& FourVector::operator+=(const FourVector& rhs)
{
	t += rhs.t;
	x += rhs.x;
	intervalFourVector();
	return *this;
}

FourVector& FourVector::operator-=(const FourVector& rhs)
{
	t -= rhs.t;
	x -= rhs.x;
	intervalFourVector();
	return *this;
}

FourVector& FourVector::operator*=(const double rhs)
{
	t *= rhs;
	x *= rhs;
	intervalFourVector();
	return *this;
}

FourVector& FourVector::operator/=(const double rhs)
{
	t /= rhs;
	x /= rhs;
	intervalFourVector();
	return *this;
}

FourVector& FourVector::operator=(const FourVector& rhs)
{
	if (&rhs != this)
	{
		t = rhs.t;
		x = rhs.x;
		intervalFourVector();
	}
	return *this;
}


//Calculate the interval of a four-vector
void FourVector::intervalFourVector() 
{
	double x1 = x.getX();
	double x2 = x.getY();
	double x3 = x.getZ();
	s = (t * t) - ( (x1 * x1) + (x2 * x2) + (x3 * x3));
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


