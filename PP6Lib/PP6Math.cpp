#include "PP6Math.hpp"

#include <iostream>
#include <climits>
#include <cmath>
#include <cstdlib>

//Definitions for PP6Math functions

int add( double a, double b, double& out1)
{
	out1 = a + b;
	return 0;
}

int subtract( double a, double b, double& out1)
{
	out1 = a - b;
	return 0;
}

int multiply( double a, double b, double& out1)
{
	out1 = a * b;
	return 0;
}

int divide( double a, double b, double& out1)
{
	if ( 0 == b )
	{ 
		return 1;
	}
	else
	{
		out1 = a / b;
		
		return 0;
	}
}

//Calculates intercept of a line on the x-axis
int intercept( double a, double b, double& out1)
{
	if ( 0 == a )
	{
		return 1;
	}
	else
	{
		out1 = (- b) / a;
	
		return 0;		
	}

}

//Solves a quadratic equation with a positive square root
int quadratic( double a, double b, double c, double& out1, double& out2 )
{
		
	//Check that the quadratic equation has real roots
	if ( (( b * b ) - ( 4 * a * c ) ) < 0 )
 	{
		return 1;	
	}
	else
	{
		//out1 and out2 are the solutions of the quadratic equation
		out1 = ( (-b) + sqrt((( b * b ) - ( 4 * a * c))))/( 2 * a);
		out2 = ( (-b) - sqrt((( b * b ) - ( 4 * a * c))))/( 2 * a);

		return 0;
	}
}

//Gives the real part of the solution of a quadratic with complex solutions
//double compquadreal( double a, double b)
//{
//	return ( (-b) / (2 * a));
//}

//Give the positive imaginary part of the solution of a quadratic with complex solutions
//double compquadim( double a, double b, double c)
//{
//	return (sqrt(-( ( b * b ) - ( 4 * a * c ) ))/( 2 * a ) );
//}
//Calculates length of a 3 vector
int threevector( double a, double b, double c, double& out1)
{
	out1 = sqrt ( (a * a) + (b * b) + (c * c));
	return 0;
}

//Calculates length of a 4 vector
int fourvector( double a, double b, double c, double d, double& out1)
{
	out1 = sqrt (std::abs( (a * a) - ( (b * b) + (c * c) + (d * d)) )  );
	return 0;
}

double energy( double a, double b, double c, double d)
{
	return sqrt ( (a*a) + (b*b) + (c*c) + (d*d) ); 
}

void print(char a, double b)
{
	std::cout << "Result of " << a <<" operation is: " << b << std::endl;
}

void swap( double& a, double& b)
{
	double c = a;
	
	a = b;
	b = c;
}

void swap( int& a, int& b)
{
	int c = a;
	
	a = b;
	b = c;
}

double inputcheck()
{
	double input(0);	
	std::cin >> input;

	while (!std::cin)
	{
		std::cerr << "Error in input of number" << std::endl;
		//Clear buffer to reset for next loop

		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		
		std::cin >> input;
	}
	return input;
}

void bubblesort( double a[], int location[], int size)
{
	double a_temp[size];
	for (int i(0); i < size; i++)
	{
	a_temp[i] = a[i];
	}		

	bool finish(false);

	while ( finish == false )
		{
		finish = true;
		for ( int k=0; k < (size-1); ++k )
			{
				if ( a_temp[k] < a_temp[(k + 1)])
				{
					swap ( a_temp[k], a_temp[k+1] );
					swap ( location[k], location[k+1] );
					finish = false;
				}
				
			}
		}
}

//Sorts a multidimensional array
void bubblesortmulti( double a[][5], int location[], int size, int component)
{
	double a_temp[size][5];
	for (int i(0); i < size; i++)
	{
		a_temp[i][component] = a[i][component];
	}

	bool finish(false);

	while ( finish == false )
		{
		finish = true;
		for ( int k=0; k < (size-1); ++k )
			{
				if ( a_temp[k][component] < a_temp[(k + 1)][component])
				{
					swap ( a_temp[k][4], a_temp[k+1][4] );
		
					swap ( location[k], location[k+1] );
					finish = false;
				}
				
			}
		}
}

void generate( double a[][4], int i, double& mean, double& sd)
{
	double px(0), py(0), pz(0), m(0), E(0), Etot(0), Esqtot(0), meanEsq(0);
	
	for ( int j=0; j < i; ++j)
	{
		px = rand()%100;
	       	py = rand()%100;
		pz = rand()%100;
		m = rand()%100;

		E = sqrt( ( m * m ) + (px * px) + (py * py) + (pz * pz) );

		a[j][0] = E;
		a[j][1] = px;
		a[j][2] = py;
		a[j][3] = pz;

		Etot += E;
		Esqtot += (E*E);
	}
	divide (Etot, i, mean);
	divide (Esqtot, i, meanEsq);

	sd = sqrt(meanEsq - (mean * mean));
}



