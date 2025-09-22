#ifndef GYOZA_SIMPLE_ELECTROSTATISTIC_EXP_HPP
#define GYOZA_SIMPLE_ELECTROSTATISTIC_EXP_HPP

#include "../engine/electrostatics/electrostatics.hpp"
#include <vector>

namespace exp1
{
    extern std::vector<gyoza::Electric_molecule> molecules;

    void Setup();
    void Start();
    void Expansion();
}


#endif
