#ifndef FOURVECTOR_HPP
#define FOURVECTOR_HPP

//Declare four vector struct
struct FourVector;

//Creator and destroyer functions
FourVector* createFourVector();

void destroyFourVector(FourVector *&fv);

//Set the values of the four vector
void setFourVector (FourVector *fv, double t, double x, double y, double z);

//Retrieve the values of a four-vector
void getFourVector ( FourVector *fv, double& t, double& x, double&y, double& z);

//Definition for four-vector boost
int boost_z( FourVector *fv, double v);

//Calculate the interval of a four-vector
int interval( FourVector *fv, double& interval);

#endif // FOURVECTOR_HPP
