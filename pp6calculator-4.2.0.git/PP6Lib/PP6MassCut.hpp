#ifndef PP6MASSCUT_HH
#define PP6MASSCUT_HH

#include "PP6Cut.hpp"

class MassCut : public Cut {
	public:
		MassCut(char cutType, double cutValOne);
		MassCut(char cutType, double cutValOne, double cutValTwo);
		virtual ~MassCut();
		virtual bool select(const Particle& input) const;
		virtual std::vector<Particle> select(const std::vector<Particle>& inputVector) const;

	private:
		const char cutType_;
		const double cutValOne_;
		const double cutValTwo_;

};

#endif // PP6MASSCUT_HH
