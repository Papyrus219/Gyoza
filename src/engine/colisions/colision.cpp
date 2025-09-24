#include "./colision.hpp"
#include <cmath>

bool gyoza::Circle_circle_colision(Circle& a, Circle& b, Manifold* m)
{
    m->a = &a;
    m->b = &b;

    float distance = std::sqrt( ( (b.possition.x - a.possition.x) * (b.possition.x - a.possition.x) ) + ( (b.possition.y - a.possition.y) * (b.possition.y - a.possition.y) ) );
    float radiant_sum = a.radius + b.radius;

    if(distance >= radiant_sum)
    {
        return false;
    }

    m->normal = Normalize( b.possition - a.possition );
    m->penetration = radiant_sum - distance;

    return true;
}

void gyoza::Resolve_colision(Physic_body& a, Physic_body& b, Manifold* m)
{
    Vec2 relativeVelocity{ b.velocity - a.velocity };

    float e = 0.501;

    float j = -(1 + e) *  Vec2::Dot_point(relativeVelocity, m->normal);
    j /= (1.0f / a.mass) + (1.0f / b.mass);

    a.velocity -= j/a.mass * m->normal;
    b.velocity += j/b.mass * m->normal;
}

void gyoza::Penetration_corection(Physic_body& a, Physic_body& b, Manifold* m)
{
    a.possition += (-m->normal * m->penetration / 2.0f);
    b.possition += (m->normal * m->penetration / 2.0f);
}
