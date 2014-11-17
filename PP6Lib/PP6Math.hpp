#ifndef PP6CALCULATOR_PP6MATH_HH
#define PP6CALCULATOR_PP6MATH_HH

//Declarations got PP6Math functions

int add(double a, double b, double& out1);
int subtract( double a, double b, double& out1);
int multiply( double a, double b, double& out1);
int divide( double a, double b, double& out1);
int intercept( double a, double b, double& out1);
int quadratic( double a, double b, double c, double& out1, double& out2 );
int threevector( double a, double b, double c, double& out1);
int fourvector( double a, double b, double c, double d, double& out1);
double energy( double a, double b, double c, double d);
void print(char a, double b);
void swap( double& a, double& b);
double inputcheck();
void bubblesort( double *a, double *l, int i );
void bubblesortmulti( double a[][5], double l[][2], int i, int j );
void generate( double a[][4], int i, double& mean, double& sd );

#endif // PP6CALCULATOR_PP6MATH_HH
