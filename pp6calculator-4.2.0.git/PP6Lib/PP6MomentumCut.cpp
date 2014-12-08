#include "PP6MomentumCut.hpp"

#include <cmath>
#include <iostream>
#include <vector>

#include "PP6Particle.hpp"

MomentumCut::MomentumCut(char cutType, double cutValOne)
	: cutType_(cutType),
	  cutValOne_(cutValOne),
	  cutValTwo_(0)
{}

MomentumCut::MomentumCut(char cutType, double cutValOne, double cutValTwo)
        : cutType_(cutType),
          cutValOne_(cutValOne),
          cutValTwo_(cutValTwo)
{}

MomentumCut::~MomentumCut()
{} 

bool MomentumCut::select(const Particle& input) const
{
	double particleMomentum(input.getMagMomentum());
	
	if ( cutType_ == '>' )
	{
		if ( particleMomentum > cutValOne_ ) {return true;}
		else {return false;} 
	}
	
	else if ( cutType_ == '<' )
	{
		if ( particleMomentum < cutValOne_ ) {return true;}
		else {return false;}
	}
	
	else if ( cutType_ == 'r' )
	{
		if ( cutValOne_ < cutValTwo_ )	
		{
			if ( particleMomentum > cutValOne_ && particleMomentum < cutValTwo_ ) {return true;}
			else {return false;}
		}
		else
		{
			if ( particleMomentum < cutValOne_ && particleMomentum > cutValTwo_ ) {return true;}
                        else {return false;} 
	}
	else {return false;}
}

std::vector<Particle> MomentumCut::select(const std::vector<Particle>& inputVector) const
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
