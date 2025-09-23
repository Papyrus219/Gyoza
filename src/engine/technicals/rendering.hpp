#ifndef GYOZA_RENDERING_HPP
#define GYOZA_RENDERING_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "../electrostatics/electrostatics.hpp"

namespace gyoza
{
    void Render(std::vector<std::unique_ptr<gyoza::Electric_molecule>> &mol, sf::RenderWindow &window);
}

#endif
