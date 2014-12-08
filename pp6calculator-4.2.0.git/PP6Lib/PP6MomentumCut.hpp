#ifndef PP6MOMENTUMCUT_HH
#define PP6MOMENTUMCUT_HH

#include "PP6Cut.hpp"

class MomentumCut : public Cut {
	public:
		MomentumCut(char cutType, double cutValOne);
		MomentumCut(char cutType, double cutValOne, double cutValTwo);
		virtual ~MomentumCut();
		virtual bool select(const Particle& input) const;
		virtual std::vector<Particle> select(const std::vector<Particle>& inputVector) const;

	private:
		const char cutType_;
		const double cutValOne_;
		const double cutValTwo_;

};

#endif // PP6MOMENTUMCUT_HH
