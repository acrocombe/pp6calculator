#include "PP6MassCut.hpp"

#include <cmath>
#include <iostream>
#include <vector>

#include "PP6Particle.hpp"

MassCut::MassCut(char cutType, double cutValOne)
	: cutType_(cutType),
	  cutValOne_(cutValOne),
	  cutValTwo_(0)
{}

MassCut::MassCut(char cutType, double cutValOne, double cutValTwo)
        : cutType_(cutType),
          cutValOne_(cutValOne),
          cutValTwo_(cutValTwo)
{}

MassCut::~MassCut()
{} 

bool MassCut::select(const Particle& input) const
{
	double particleMass(input.getMassGeV());
	
	if ( cutType_ == '>' )
	{
		if ( particleMass > cutValOne_ ) {return true;}
		else {return false;} 
	}
	
	else if ( cutType_ == '<' )
	{
		if ( particleMass < cutValOne_ ) {return true;}
		else {return false;}
	}
	
	else if ( cutType_ == 'r' )
	{
		if ( cutValOne_ < cutValTwo_ )	
		{
			if ( particleMass > cutValOne_ && particleMass < cutValTwo_ ) {return true;}
			else {return false;}
		}
		else
		{
			if ( particleMass < cutValOne_ && particleMass > cutValTwo_ ) {return true;}
                        else {return false;} 
	}
	else {return false;}
}

std::vector<Particle> MassCut::select(const std::vector<Particle>& inputVector) const
{
	size_t nParticles = inputVector.size();
	std::vector<Particle> cutVector;

	for (size_t i(0); i < nParticles; ++i)
	{
		bool accept(select(inputVector.at(i)));
		
		if (accept == true)
		{
			cutVector.push_back(inputVector.at(i));
		}
	}
	return cutVector;	
}
