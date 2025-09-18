#ifndef VEC2_HPP
#define VEC2_HPP

#include<iostream>

struct Vec2
{
    Vec2(float x_, float y_);
    Vec2() = default;

    float x{};
    float y{};

    float Get_squred_lenght();
    static float Dot_point(Vec2 a, Vec2 b);
    static float Dot_point(float a, float b, float alpha);
    Vec2 operator*(float a);
    Vec2 operator/(float a);
    Vec2& operator*=(float a);
    Vec2& operator/=(float a);
    Vec2 operator+(Vec2 a);
    Vec2 operator-(Vec2 a);
    Vec2& operator+=(Vec2 a);
    Vec2& operator-=(Vec2 a);
    Vec2 operator-();
    bool operator==(Vec2 a);

    friend Vec2 operator*(float a, Vec2 b);
    friend std::ostream & operator<<(std::ostream &cout, Vec2 &x);
};

Vec2 Normalize(Vec2 v);
Vec2 operator*(float a, Vec2 b);
std::ostream & operator<<(std::ostream &cout, Vec2 &x);

#endif
