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

    void spawnParticle(real mass, real radius, Vector2D position, Vector2D velocity);
    void spawnParticles(
        int qty, real mass, real radius, Vector2D startArea, Vector2D endArea, real minVelocity, real maxVelocity
    );

    const std::vector<Particle>& getParticles() const;

private:
    std::vector<Particle> particles_;

    void detectCollisions();
    void resolveCollisions();

    struct Collision
    {
        int a;
        int b;
    };
    std::vector<Collision> collisionsPP_;
};

} // namespace carom::physics
