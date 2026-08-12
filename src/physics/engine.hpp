#pragma once

#include "physics/types/particle.hpp"
#include "physics/types/real.hpp"
#include "physics/types/vector2d.hpp"

#include <vector>

namespace carom::physics {

class Engine
{
public:
    void update(real dt);

    void addParticle(real mass, real radius, Vector2D position, Vector2D velocity);

    const std::vector<Particle>& getParticles() const;

private:
    std::vector<Particle> particles;
};

} // namespace carom::physics
