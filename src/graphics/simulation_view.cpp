#include "graphics/simulation_view.hpp"

#include <vector>

namespace carom::graphics {

void SimulationView::render(sf::RenderTarget& target, const std::vector<physics::Particle> particles) const
{
    target.clear(backGroundColor);
    target.setView(camera_);

    sf::CircleShape circle;
    for (auto& particle : particles)
    {
        circle.setRadius(particle.radius);
        circle.setOrigin({static_cast<float>(particle.radius), static_cast<float>(particle.radius)});
        circle.setPosition({static_cast<float>(particle.position.x), static_cast<float>(particle.position.y)});
        circle.setFillColor(particleColor);
        target.draw(circle);
    }
}

sf::View& SimulationView::getCamera()
{
    return camera_;
}

} // namespace carom::graphics
