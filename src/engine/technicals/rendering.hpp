#ifndef GYOZA_RENDERING_HPP
#define GYOZA_RENDERING_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "../electrostatics/electrostatics.hpp"

namespace gyoza
{
    void Render(std::vector<gyoza::Electric_molecule> &mol, sf::RenderWindow &window);
}

#endif
