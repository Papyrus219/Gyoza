#include <cmath>
#include "electrostatics.hpp"

gyoza::Electric_molecule::Electric_molecule(Molecule_type type_, Vec2 possition_): electric_charge{Get_molecule_charge(type_)}, mass{Get_molecule_mass(type_)}, inv_mass{1/mass}, size{10}, possition{possition_}
{
    sprite.setRadius(10);
    sprite.setPosition({possition_.x,possition_.y});

    switch(type_)
    {
        case Molecule_type::electron:
            sprite.setFillColor(sf::Color::Cyan);
            break;
        case Molecule_type::proton:
            sprite.setFillColor(sf::Color::Red);
            break;
        case Molecule_type::neutron:
            sprite.setFillColor(sf::Color{80,80,80});
            break;
    }
}

gyoza::Electric_molecule::Electric_molecule(Molecule_type type_, Vec2 possition_, float size_): electric_charge{Get_molecule_charge(type_)}, mass{Get_molecule_mass(type_)}, inv_mass{ (mass != 0)? 1/mass : 1 }, size{size_}, possition{possition_}
{
    sprite.setRadius(size_);
    sprite.setPosition({possition_.x,possition_.y});

    switch(type_)
    {
        case Molecule_type::electron:
            sprite.setFillColor(sf::Color::Cyan);
            break;
        case Molecule_type::proton:
            sprite.setFillColor(sf::Color::Red);
            break;
        case Molecule_type::neutron:
            sprite.setFillColor(sf::Color{80,80,80});
            break;
    }
}

void gyoza::Impact(Electric_molecule& a, Electric_molecule& b)
{
    double dx = b.possition.x - a.possition.x;
    double dy = b.possition.y - a.possition.y;
    double softening = 5.0;

    double distance_squred = (dx*dx) + (dy*dy) + (softening*softening);

    Vec2 direction = Normalize(b.possition - a.possition);

    double impact_force = electrostaic_constant * ( (a.electric_charge * b.electric_charge) / distance_squred);

    Vec2 force = direction * impact_force;

    a.velocity -= (force * a.inv_mass);
    b.velocity += (force * b.inv_mass);
}

void gyoza::Electric_molecule::Update(double delta_time)
{
    possition += velocity * delta_time;

    velocity *= 0.998;

    sprite.setPosition({possition.x,possition.y});
}

void gyoza::Molecules_reactions(std::vector<std::unique_ptr<gyoza::Electric_molecule>>& mol)
{
    for(int i=0;i<mol.size();i++)
    {
        for(int j=i+1;j<mol.size();j++)
        {
            gyoza::Impact(*mol[i],*mol[j]);
        }
    }

    for(auto &el : mol)
    {
        el->Update(0.016666667);
    }
}
