#include <iostream>
#include <climits>
#include <cmath>

#include "ThreeVector.hpp"

//Definitions for ThreeVector constructors
ThreeVector::ThreeVector(const double x_, const double y_, const double z_) : x(x_), y(y_), z(z_), len(0)
{
	lengthThreeVector();
}

ThreeVector::ThreeVector(const ThreeVector& other) : x(other.x), y(other.y), z(other.z), len(other.len)
{}

void ThreeVector::setX(double x_)
{
	x = x_;
	lengthThreeVector();
}

void ThreeVector::setY(double y_)
{
	y = y_;
	lengthThreeVector();
}

void ThreeVector::setZ(double z_)
{
	z = z_;
	lengthThreeVector();
}


//Definitions for operator overloads
ThreeVector& ThreeVector::operator+=(const ThreeVector& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	lengthThreeVector();
	return *this;
}

ThreeVector& ThreeVector::operator-=(const ThreeVector& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	lengthThreeVector();
	return *this;
}

ThreeVector& ThreeVector::operator*=(const double rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
	lengthThreeVector();
	return *this;
}

ThreeVector& ThreeVector::operator/=(const double rhs)
{
	x /= rhs;
	y /= rhs;
	z /= rhs;
	lengthThreeVector();
	return *this;
}

ThreeVector& ThreeVector::operator=(const ThreeVector& rhs)
{
	if (&rhs != this)
	{
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		lengthThreeVector();
	}
	return *this;
}

//Calculate the length of a three-vector
void ThreeVector::lengthThreeVector()
{
	len = sqrt( (x * x) + (y * y) + (z * z) );
}

//Free operators for the ThreeVector class
ThreeVector operator+(const ThreeVector& lhs, const ThreeVector& rhs)
{
	ThreeVector temp(lhs);
	temp += rhs;
	return temp;
}

ThreeVector operator-(const ThreeVector& lhs, const ThreeVector& rhs)
{
	ThreeVector temp(lhs);
	temp -= rhs;
	return temp;
}

std::istream& operator>>(std::istream& stream, ThreeVector& fv)
{
	double x, y, z;
	stream >> x >> y >> z;
	fv.setX(x);
	fv.setY(y);
	fv.setZ(z);
	return stream;
}

std::ostream& operator<<(std::ostream& stream, const ThreeVector& fv)
{
	stream << "[" << fv.getX() << ", " << fv.getY() << ", " << fv.getZ() << "]";
	return stream;
}
