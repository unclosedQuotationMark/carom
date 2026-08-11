#include "graphics/simulation_view.hpp"

namespace carom::graphics {

void SimulationView::render(sf::RenderTarget& target) const
{
    target.clear(backGroundColor);

    sf::CircleShape particle(100);
    particle.setOrigin({100, 100});
    particle.setFillColor(particleColor);

    target.setView(camera_);
    target.draw(particle);
}

sf::View& SimulationView::getCamera()
{
    return camera_;
}

} // namespace carom::graphics
