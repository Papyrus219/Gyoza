#include"vec2.hpp"
#include<cmath>

Vec2::Vec2(float x_, float y_): x{x_}, y{y_}
{};

float Vec2::Get_squred_lenght()
{
    return (x*x + y*y);
}


Vec2 Vec2::operator*(float a)
{
    Vec2 result = *this;

    result.x *= a;
    result.y *= a;

    return result;
}

Vec2 operator*(float a, Vec2 b)
{
    Vec2 result = b;

    result.x *= a;
    result.y *= a;

    return result;
}

Vec2 Vec2::operator/(float a)
{
    Vec2 result = *this;

    result.x /= a;
    result.y /= a;

    return result;
}

Vec2& Vec2::operator*=(float a)
{
    this->x *= a;
    this->y *= a;

    return *this;
}

Vec2& Vec2::operator/=(float a)
{
    this->x /= a;
    this->y /= a;

    return *this;
}


Vec2 Vec2::operator+(Vec2 a)
{
    Vec2 result{};

    result.x = this->x + a.x;
    result.y = this->y + a.y;

    return result;
}

Vec2 Vec2::operator-(Vec2 a)
{
    Vec2 result{};

    result.x = this->x - a.x;
    result.y = this->y - a.y;

    return result;
}

Vec2& Vec2::operator+=(Vec2 a)
{
    this->x += a.x;
    this->y += a.y;

    return *this;
}

Vec2& Vec2::operator-=(Vec2 a)
{
    this->x -= a.x;
    this->y -= a.y;

    return *this;
}

Vec2 Vec2::operator-()
{
    Vec2 result{};

    result.x = -(this->x);
    result.y = -(this->y);

    return result;
}

bool Vec2::operator==(Vec2 a)
{
    if(this->x != a.x) return false;
    if(this->y != a.y) return false;

    return true;
}

std::ostream & operator<<(std::ostream& cout, Vec2& x)
{
    std::cout << "[ " << x.x << " | " << x.y << " ]";

    return cout;
}


float Vec2::Dot_point(Vec2 a, Vec2 b)
{
    float result{};

    result += (a.x * b.x);
    result += (a.y * b.y);

    return result;
}

float Vec2::Dot_point(float a, float b, float alpha)
{
    float result = (a * b) * std::cos(alpha);

    return result;
}

Vec2 Normalize(Vec2 a)
{
    if( (a.x * a.x) + (a.y * a.y) == 0) return {1,0};

    float length = std::sqrt((a.x * a.x) + (a.y * a.y));

    return{a.x / length , a.y / length };
}
