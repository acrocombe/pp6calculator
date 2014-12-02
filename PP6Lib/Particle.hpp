#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "FourVector.hpp"

class Particle 
{
	public: 
		//Constructors		
		Particle();
		Particle(const Particle& other);
		Particle(const int pdg_code_, const double mass_);
		Particle(const int pdg_code_, const double mass_, const ThreeVector& threemomentum_);
		Particle(const int pdg_code_, const double mass_, const double px_, const double py_, const double pz_);

		// Public member functions
		void setMass(const double mass_);
		void setPDGCode(const int pdg_code_){pdg_code = pdg_code_;} 
		void setThreeMomentum(const ThreeVector& threemomentum_); 
		void setThreeMomentum(const double px_, const double py_, const double pz_); 
		
		double getEnergy() const { return momentum.getT();}
		FourVector getFourMomentum() const { return momentum;}
		double getMagMomentum() const { return getThreeMomentum().length();} 
		double getMassGeV() const { return mass;}
		int getPDGCode() const { return pdg_code;}
		ThreeVector getThreeMomentum() const { return momentum.getThreeVector();}

		//Operator overloads
		Particle& operator=(const Particle& rhs);	

	private:
		//Member variables
		int pdg_code;
		double mass;
		FourVector momentum;
};

#endif // PARTICLE_HPP
