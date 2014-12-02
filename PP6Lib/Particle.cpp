#include <iostream>
#include <climits>
#include <cmath>

#include "Particle.hpp"
#include "FourVector.hpp"

//Definitions for Particle constructors
Particle::Particle()
{
	pdg_code = 0;
	mass = 0;
	momentum = FourVector();
}

Particle::Particle(const Particle& other) : pdg_code(other.pdg_code), mass(other.mass), momentum(other.momentum)
{}

Particle::Particle(const int pdg_code_, const double mass_) : pdg_code(pdg_code_), mass(mass_), momentum(mass_, ThreeVector())
{}	

Particle::Particle(const int pdg_code_, const double mass_, const ThreeVector& threemomentum_) : pdg_code(pdg_code_), mass(mass_), momentum(mass_, ThreeVector(threemomentum_))
{}

Particle::Particle(const int pdg_code_, const double mass_, const double px_, const double py_, const double pz_)
{
	pdg_code = pdg_code_;
	mass = mass_;
	ThreeVector threemomentum(px_, py_, pz_);
	setThreeMomentum(threemomentum);
}

//Set functions

void Particle::setMass(const double mass_)
{
	mass = mass_;
	ThreeVector threemomentum = getThreeMomentum();
	setThreeMomentum(threemomentum);
}

void Particle::setThreeMomentum(const ThreeVector& threemomentum_)
{
	double threemom_length = threemomentum_.length();
	double E = sqrt(threemom_length*threemom_length + mass*mass);
	momentum.setT(E);
	momentum.setThreeVector(threemomentum_);
}

void Particle::setThreeMomentum(const double px_, const double py_, const double pz_)
{
	ThreeVector threemomentum(px_, py_, pz_);
	setThreeMomentum(threemomentum);
}
