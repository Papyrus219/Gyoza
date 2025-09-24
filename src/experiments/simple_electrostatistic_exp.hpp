#ifndef GYOZA_SIMPLE_ELECTROSTATISTIC_EXP_HPP
#define GYOZA_SIMPLE_ELECTROSTATISTIC_EXP_HPP

#include "../engine/electrostatics/electrostatics.hpp"
#include <vector>
#include <memory>

namespace exp1
{
    extern std::vector< std::unique_ptr<gyoza::Electric_molecule>> molecules;

    void Start(std::string &mode);

    void Text_setup();
    void Mouse_setup(sf::RenderWindow *window);
    void Text_expansion();

    enum Setup_mode
    {
        text = 1,
        mouse = 2
    };
}


#endif
