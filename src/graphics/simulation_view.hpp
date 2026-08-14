#pragma once

#include "graphics/constants.hpp"
#include "physics/engine.hpp"
#include "physics/types/particle.hpp"
#include "physics/types/static_body.hpp"

#include <SFML/Graphics.hpp>
#include <vector>

namespace carom::graphics {

class SimulationView
{
public:
    void render(sf::RenderTarget& target, const physics::Engine& engine) const;
    sf::View& getCamera();

private:
    sf::View camera_{{0.f, 0.f}, {windowWidth, windowHeight}};

    void renderParticles(sf::RenderTarget& target, const std::vector<physics::Particle>& data) const;
    void renderStaticBodies(sf::RenderTarget& target, const std::vector<physics::StaticBody>& data) const;
};

} // namespace carom::graphics
