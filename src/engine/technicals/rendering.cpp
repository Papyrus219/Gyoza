#include "rendering.hpp"

void gyoza::Render(std::vector<std::unique_ptr<gyoza::Electric_molecule>>& mol, sf::RenderWindow& window)
{
    for(auto &el : mol)
    {
        window.draw(el->sprite);
    }
}
