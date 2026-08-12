#pragma once

#include "graphics/constants.hpp"
#include "physics/types/particle.hpp"

#include <SFML/Graphics.hpp>

namespace carom::graphics {

class SimulationView
{
public:
    void render(sf::RenderTarget& target, const std::vector<physics::Particle> particles) const;
    sf::View& getCamera();

private:
    sf::View camera_{{0.f, 0.f}, {windowWidth, windowHeight}};
};

} // namespace carom::graphics
