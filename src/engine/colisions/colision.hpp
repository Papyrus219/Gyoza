#ifndef GYOZA_COLISION_HPP
#define GYOZA_COLISION_HPP

#include "../structures/vec2.hpp"

namespace gyoza
{
    struct Physic_body
    {
        Physic_body(double mass_, Vec2 possition_): mass{mass_}, inv_mass{ (mass > 0)? 1/mass : 1 }, possition{possition_}
        {};

        const double mass{};
        const double inv_mass{};

        Vec2 possition{};
        Vec2 velocity{};
    };

    struct Circle: public Physic_body
    {
        Circle(double mass_, Vec2 possition_, float radius_): Physic_body{mass_,possition_}, radius{radius_}
        {};

        const float radius{};
    };

    struct Manifold
    {
        Physic_body *a{};
        Physic_body *b{};

        Vec2 normal{};
        float penetration{};
    };


    bool Circle_circle_colision(Circle &a, Circle &b, Manifold *m);
    void Resolve_colision(Physic_body &a, Physic_body &b, Manifold *m);
    void Penetration_corection(Physic_body &a, Physic_body &b, Manifold *m);
}

#endif
