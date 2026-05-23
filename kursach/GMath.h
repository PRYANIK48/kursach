#pragma once
#include <SFML/System/Vector2.hpp>

using sf::Vector2f;

namespace GMath
{
    float Length(const Vector2f& v);

    Vector2f Normalize(const Vector2f& v);

    Vector2f Multiply(const Vector2f& v, float value);

    Vector2f Divide(const Vector2f& v, float value);

    Vector2f Direction(const Vector2f& from, const Vector2f& to);

    float Distance(const Vector2f& a, const Vector2f& b);

    float AngleBetweenPoints(const Vector2f& from, const Vector2f& to);

    float AngleBetweenVectors(const Vector2f& a, const Vector2f& b);
}