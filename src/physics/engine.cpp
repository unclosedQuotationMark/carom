#include "physics/engine.hpp"

namespace carom::physics {

void Engine::update(real dt)
{
    for (auto& particle : particles)
    {
        particle.position += particle.velocity * dt;
    }
}

void Engine::addParticle(real mass, real radius, Vector2D position, Vector2D velocity)
{
    particles.emplace_back(mass, radius, position, velocity);
}

const std::vector<Particle>& Engine::getParticles() const
{
    return particles;
}

} // namespace carom::physics
