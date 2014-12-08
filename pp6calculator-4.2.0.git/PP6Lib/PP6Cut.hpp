#ifndef PP6CUT_HH
#define PP6CUT_HH

#include <iostream>
#include <vector>

class Particle;

class Cut 
{
	public: 
		virtual ~Cut() {}

		virtual bool select(const Particle& input) const = 0;
		virtual std::vector<Particle> select(const std::vector<Particle>& inputVector) const = 0;
};

#endif // PP6CUT_HH
