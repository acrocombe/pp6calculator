#ifndef PP6ENERGYCUT_HH
#define PP6ENERGYCUT_HH

#include "PP6Cut.hpp"

class EnergyCut : public Cut {
        public:
                EnergyCut(char cutType, double cutValOne);
                EnergyCut(char cutType, double cutValOne, double cutValTwo);
                virtual ~EnergyCut();
                virtual bool select(const Particle& input) const;
                virtual std::vector<Particle> select(const std::vector<Particle>& inputVector) const;

        private:
                const char cutType_;
                const double cutValOne_;
                const double cutValTwo_;

};

#endif // PP6ENERGYCUT_HH
~                            
