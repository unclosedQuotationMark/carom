#pragma once

#include <physics/types/real.hpp>
#include <physics/types/vector2d.hpp>

namespace carom::physics {

struct StaticBody
{
    Vector2D size;
    Vector2D position;
    bool isOrinted;
    real angle;
};

} // namespace carom::physics
