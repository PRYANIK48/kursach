#include "GMath.h"
#include <cmath>

float GMath::Length(const Vector2f& v)
{
    return std::sqrt(v.x * v.x + v.y * v.y);
}

Vector2f GMath::Normalize(const Vector2f& v)
{
    float len = Length(v);

    if (len == 0.f)
        return Vector2f(0.f, 0.f);

    return Vector2f(v.x / len, v.y / len);
}

Vector2f GMath::Multiply(const Vector2f& v, float value)
{
    return Vector2f(v.x * value, v.y * value);
}

Vector2f GMath::Divide(const Vector2f& v, float value)
{
    if (value == 0.f)
        return Vector2f(0.f, 0.f);

    return Vector2f(v.x / value, v.y / value);
}

Vector2f GMath::Direction(const Vector2f& from, const Vector2f& to)
{
    return Normalize(to - from);
}

float GMath::Distance(const Vector2f& a, const Vector2f& b)
{
    return Length(Vector2f(b.x - a.x, b.y - a.y));
}

float GMath::AngleBetweenPoints(const Vector2f& from, const Vector2f& to)
{
    Vector2f dir = to - from;
    float angle = std::atan2(dir.y, dir.x) * 180.f / 3.14159265f;

    angle += 90.f;
    if (angle < 0.f)
        angle += 360.f;

    return angle;
}

float GMath::AngleBetweenVectors(const Vector2f& a, const Vector2f& b)
{
    float dot = a.x * b.x + a.y * b.y;

    float lenA = Length(a);
    float lenB = Length(b);

    if (lenA == 0.f || lenB == 0.f)
        return 0.f;

    float cosAngle = dot / (lenA * lenB);

    if (cosAngle > 1.f)
        cosAngle = 1.f;

    if (cosAngle < -1.f)
        cosAngle = -1.f;

    return std::acos(cosAngle) * 180.f / 3.14159265f;
}