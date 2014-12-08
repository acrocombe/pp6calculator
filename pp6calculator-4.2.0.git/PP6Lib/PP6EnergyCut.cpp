#include "PP6EnergyCut.hpp"

#include <cmath>
#include <iostream>
#include <vector>

#include "PP6Particle.hpp"

EnergyCut::EnergyCut(char cutType, double cutValOne)
	: cutType_(cutType),
	  cutValOne_(cutValOne),
	  cutValTwo_(0)
{}

EnergyCut::EnergyCut(char cutType, double cutValOne, double cutValTwo)
        : cutType_(cutType),
          cutValOne_(cutValOne),
          cutValTwo_(cutValTwo)
{}

EnergyCut::~EnergyCut()
{} 

bool EnergyCut::select(const Particle& input) const
{
	double particleEnergy(input.getEnergy());
	
	if ( cutType_ == '>' )
	{
		if ( particleEnergy > cutValOne_ ) {return true;}
		else {return false;} 
	}
	
	else if ( cutType_ == '<' )
	{
		if ( particleEnergy < cutValOne_ ) {return true;}
		else {return false;}
	}
	
	else if ( cutType_ == 'r' )
	{
		if ( cutValOne_ < cutValTwo_ )	
		{
			if ( particleEnergy > cutValOne_ && particleEnergy < cutValTwo_ ) {return true;}
			else {return false;}
		}
		else
		{
			if ( particleEnergy < cutValOne_ && particleEnergy > cutValTwo_ ) {return true;}
                        else {return false;} 
	}
	else {return false;}
}

std::vector<Particle> EnergyCut::select(const std::vector<Particle>& inputVector) const
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
