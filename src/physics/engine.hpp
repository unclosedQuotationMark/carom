#pragma once

#include "physics/types/particle.hpp"
#include "physics/types/real.hpp"
#include "physics/types/static_body.hpp"
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
    void spawnStaticBody(Vector2D size, Vector2D position, real angle = 0.0_r);

    const std::vector<Particle>& getParticles() const;
    const std::vector<StaticBody>& getStaticBodies() const;

private:
    std::vector<Particle> particles_;
    std::vector<StaticBody> staticBodies_;

    void updatePositions(real dt);
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
