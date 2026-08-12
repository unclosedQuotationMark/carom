#pragma once

#include "physics/types/real.hpp"

#include <cmath>

namespace carom::physics {

struct Vector2D
{
    real x{0.0_r};
    real y{0.0_r};

    constexpr Vector2D& operator+=(const Vector2D& other) noexcept
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    constexpr Vector2D& operator-=(const Vector2D& other) noexcept
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    constexpr Vector2D& operator*=(real scalar) noexcept
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    constexpr Vector2D& operator/=(real scalar) noexcept
    {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    [[nodiscard]] constexpr real dot(const Vector2D& other) const noexcept
    {
        return x * other.x + y * other.y;
    }

    [[nodiscard]] constexpr real lengthSquared() const noexcept
    {
        return x * x + y * y;
    }

    [[nodiscard]] real length() const noexcept
    {
        return std::sqrt(lengthSquared());
    }

    void normalize() noexcept
    {
        real len = length();
        if (len > 0.0_r)
        {
            x /= len;
            y /= len;
        }
    }

    [[nodiscard]] Vector2D normalized() const noexcept
    {
        Vector2D v = *this;
        v.normalize();
        return v;
    }
};

constexpr Vector2D operator+(Vector2D lhs, Vector2D rhs) noexcept
{
    lhs += rhs;
    return lhs;
}

constexpr Vector2D operator-(Vector2D lhs, Vector2D rhs) noexcept
{
    lhs -= rhs;
    return lhs;
}

constexpr Vector2D operator*(Vector2D v, real scalar) noexcept
{
    v *= scalar;
    return v;
}

constexpr Vector2D operator*(real scalar, Vector2D v) noexcept
{
    v *= scalar;
    return v;
}

constexpr Vector2D operator/(Vector2D v, real scalar) noexcept
{
    v /= scalar;
    return v;
}

} // namespace carom::physics
