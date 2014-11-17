#ifndef FOURVECTOR_HPP
#define FOURVECTOR_HPP

class FourVector 
{
	public: 
		//Constructors		
		FourVector() { t = 0; x = 0; y = 0; z = 0; s = 0}

		FourVector(const double t_, const double x_, const double y_, const double z_);

		FourVector(const FourVector& other);

		//Example destructor

		// Public member functions
		void setFourVector( double t_, double x_, double y_, double z_); /* not finished */
		
		double getT() const { return t;};
		double getX() const { return x;};
		double getY() const { return y;};
		double getZ() const { return z;};
		double interval() const { return s;};

		int boostFourVector(const double v);

		//Operator overloads
		FourVector& operator+=(const /* not finished */

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

#endif // FOURVECTOR_HPP
