#include "physics/engine.hpp"

#include "physics/utils/math.hpp"
#include "physics/utils/random_generator.hpp"

namespace carom::physics {

void Engine::update(real dt)
{
    updatePositions(dt);
    detectCollisions();
    resolveCollisions();
}

void Engine::spawnParticle(real mass, real radius, Vector2D position, Vector2D velocity)
{
    particles_.emplace_back(mass, radius, position, velocity);
}

void Engine::spawnParticles(
    int qty, real mass, real radius, Vector2D startArea, Vector2D endArea, real minSpeed, real maxSpeed
)
{
    RandomGenerator& rd = RandomGenerator::getInstance();
    real minX = std::min(startArea.x, endArea.x);
    real maxX = std::max(startArea.x, endArea.x);
    real minY = std::min(startArea.y, endArea.y);
    real maxY = std::max(startArea.y, endArea.y);

    for (int i = 0; i < qty; ++i)
    {
        real speed = rd.getReal(minSpeed, maxSpeed);
        real angle = rd.getAngle();
        Vector2D velocity = speed * Vector2D{std::sin(angle), std::cos(angle)};
        real x = rd.getReal(minX, maxX);
        real y = rd.getReal(minY, maxY);
        particles_.emplace_back(mass, radius, Vector2D{x, y}, velocity);
    }
}

void Engine::spawnStaticBody(Vector2D size, Vector2D position, real angle)
{
    bool isOriented = math::isZero(angle);
    staticBodies_.emplace_back(size, position, isOriented, angle);
}

const std::vector<Particle>& Engine::getParticles() const
{
    return particles_;
}

const std::vector<StaticBody>& Engine::getStaticBodies() const
{
    return staticBodies_;
}

void Engine::updatePositions(real dt)
{
    for (auto& particle : particles_)
    {
        particle.position += particle.velocity * dt;
    }
}

void Engine::detectCollisions()
{
    collisionsPP_.clear();

    for (std::ptrdiff_t i = 0; i < ssize(particles_); ++i)
    {
        for (std::ptrdiff_t j = i + 1; j < ssize(particles_); ++j)
        {
            real minDist = particles_[i].radius + particles_[j].radius;
            real dist2 = (particles_[i].position - particles_[j].position).lengthSquared();
            if (dist2 < minDist * minDist)
            {
                collisionsPP_.emplace_back(i, j);
            }
        }
    }

    RandomGenerator::getInstance().shuffle(collisionsPP_);
}

void Engine::resolveCollisions()
{
    for (auto col : collisionsPP_)
    {
        Particle& p1 = particles_[col.a];
        Particle& p2 = particles_[col.b];

        Vector2D delta = p2.position - p1.position;
        real distance = delta.length();

        Vector2D normal;
        if (math::isZero(distance))
        {
            real angle = RandomGenerator::getInstance().getAngle();
            normal = {std::sin(angle), std::cos(angle)};
        }
        else
        {
            normal = delta / distance;
        }

        Vector2D relativeVelocity = p1.velocity - p2.velocity;
        real velocityAlongNormal = relativeVelocity.dot(normal);

        if (velocityAlongNormal < 0)
        {
            continue;
        }

        real impulseScalar = (2 * velocityAlongNormal) / (p1.mass + p2.mass);
        p1.velocity -= normal * impulseScalar * p2.mass;
        p2.velocity += normal * impulseScalar * p1.mass;
    }
}

} // namespace carom::physics
