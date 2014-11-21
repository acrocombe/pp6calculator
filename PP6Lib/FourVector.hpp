#ifndef FOURVECTOR_HPP
#define FOURVECTOR_HPP

class FourVector 
{
	public: 
		//Constructors		
		FourVector() { t = 0; x = 0; y = 0; z = 0; s = 0;}

		FourVector(const double t_, const double x_, const double y_, const double z_);

		FourVector(const FourVector& other);

		//Example destructor

		// Public member functions
		void setT(double t_);
		void setX(double x_); 
		void setY(double y_); 
		void setZ(double z_); 
		
		double getT() const { return t;}
		double getX() const { return x;}
		double getY() const { return y;}
		double getZ() const { return z;}
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
		double x; 
		double y; 
		double z;
		double s;
		
		//Private member functions
		void intervalFourVector();
};

FourVector operator+(const FourVector& lhs, const FourVector& rhs);
FourVector operator-(const FourVector& lhs, const FourVector& rhs);

std::istream& operator>>(std::istream& stream, FourVector& fv);
std::ostream& operator<<(std::ostream& stream, const FourVector& fv);

#endif // FOURVECTOR_HPP
