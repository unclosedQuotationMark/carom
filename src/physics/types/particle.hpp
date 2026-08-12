#pragma once

#include "physics/types/real.hpp"
#include "physics/types/vector2d.hpp"

namespace carom::physics {

struct Particle
{
    real mass;
    real radius;
    Vector2D position;
    Vector2D velocity;
};

} // namespace carom::physics
