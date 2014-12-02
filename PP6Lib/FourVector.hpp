#ifndef FOURVECTOR_HPP
#define FOURVECTOR_HPP

#include "ThreeVector.hpp"

class FourVector 
{
	public: 
		//Constructors		
		FourVector() { t = 0; x.setX(0); x.setY(0); x.setZ(0); s = 0;}

		FourVector(const double t_, const ThreeVector& x_);

		FourVector(const FourVector& other);

		// Public member functions
		void setT(const double t_);
		void setX(const double x_); 
		void setY(const double y_); 
		void setZ(const double z_);
	        void setThreeVector(const ThreeVector&);	
		
		double getT() const { return t;}
		ThreeVector getThreeVector() const { return x;}
		double getX() const { return x.getX();}
		double getY() const { return x.getY();}
		double getZ() const { return x.getZ();}
		double interval() const { return s;}

		int boost_z(const double v);

		//Operator overloads
		FourVector& operator+=(const FourVector& rhs);
		FourVector& operator-=(const FourVector& rhs);
		FourVector& operator*=(const double rhs);
		FourVector& operator/=(const double rhs);
		FourVector& operator=(const FourVector& rhs);	

	private:
		//Member variables
		double t;
		ThreeVector x;
		double s;
		
		//Private member functions
		void intervalFourVector();
};

FourVector operator+(const FourVector& lhs, const FourVector& rhs);
FourVector operator-(const FourVector& lhs, const FourVector& rhs);

//std::istream& operator>>(std::istream& stream, FourVector& fv);
//std::ostream& operator<<(std::ostream& stream, const FourVector& fv);

#endif // FOURVECTOR_HPP
