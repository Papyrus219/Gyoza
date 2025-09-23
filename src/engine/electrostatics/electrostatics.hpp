#ifndef GYOZA_ELECTROSTATICS_HPP
#define GYOZA_ELECTROSTATICS_HPP

#include <SFML/Graphics.hpp>
#include "../structures/vec2.hpp"

namespace gyoza
{
    constexpr double electrostaic_constant{8.988e9};

    enum class Molecule_type
    {
        electron,
        proton,
        neutron
    };

    struct Electric_molecule
    {
        Electric_molecule(Molecule_type type_, Vec2 possition_);
        Electric_molecule(Molecule_type type_, Vec2 possition_, float size_);

        const double electric_charge{};
        const double mass{};
        const double inv_mass{};
        const float size{};

        Vec2 possition{};
        Vec2 velocity{};

        sf::CircleShape sprite{};

        void Update(double delta_time);
    };

    constexpr double Get_molecule_charge(Molecule_type type)
    {
        switch(type)
        {
            case Molecule_type::electron:
                return  -1.602e-19;
            case Molecule_type::proton:
                return 1.602e-19;
            case Molecule_type::neutron:
                return 0.0;
        }

        return 0.0;
    }

    constexpr double Get_molecule_mass(Molecule_type type)
    {
        switch(type)
        {
            case Molecule_type::electron:
                return 9.109e-31;
            case Molecule_type::proton:
                return 1.673e-27;
            case Molecule_type::neutron:
                return 1.675e-27;
        }

        return 0.0;
    }

    void Impact(Electric_molecule &a, Electric_molecule &b);
    void Molecules_reactions(std::vector<std::unique_ptr<gyoza::Electric_molecule>>& mol);
}

#endif
