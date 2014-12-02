#ifndef THREEVECTOR_HPP
#define THREEVECTOR_HPP

class ThreeVector 
{
	public: 
		//Constructors		
		ThreeVector() {x = 0; y = 0; z = 0; len = 0;}

		ThreeVector(const double x_, const double y_, const double z_);

		ThreeVector(const ThreeVector& other);

		// Public member functions
		void setX(double x_); 
		void setY(double y_); 
		void setZ(double z_); 
		
		double getX() const { return x;}
		double getY() const { return y;}
		double getZ() const { return z;}
		double length() const { return len;}

		//Operator overloads
		ThreeVector& operator+=(const ThreeVector& rhs);
		ThreeVector& operator-=(const ThreeVector& rhs);
		ThreeVector& operator*=(const double rhs);
		ThreeVector& operator/=(const double rhs);
		ThreeVector& operator=(const ThreeVector& rhs);	

	private:
		//Member variables
		double x; 
		double y; 
		double z;
		double len;

		//Private member functions
		void lengthThreeVector();
};

ThreeVector operator+(const ThreeVector& lhs, const ThreeVector& rhs);
ThreeVector operator-(const ThreeVector& lhs, const ThreeVector& rhs);

//std::istream& operator>>(std::istream& stream, ThreeVector& fv);
//std::ostream& operator<<(std::ostream& stream, const ThreeVector& fv);

#endif // THREEVECTOR_HPP	

