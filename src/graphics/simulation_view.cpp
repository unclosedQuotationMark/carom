#include "graphics/simulation_view.hpp"

#include "graphics/utils.hpp"

namespace carom::graphics {

void SimulationView::render(sf::RenderTarget& target, const physics::Engine& engine) const
{
    target.clear(backGroundColor);
    target.setView(camera_);
    renderParticles(target, engine.getParticles());
    renderStaticBodies(target, engine.getStaticBodies());
}

sf::View& SimulationView::getCamera()
{
    return camera_;
}

void SimulationView::renderParticles(sf::RenderTarget& target, const std::vector<physics::Particle>& data) const
{
    sf::CircleShape circle;
    circle.setFillColor(particleColor);
    for (auto& particle : data)
    {
        circle.setRadius(particle.radius);
        circle.setOrigin(ToVector2f({particle.radius, particle.radius}));
        circle.setPosition(ToVector2f(particle.position));
        target.draw(circle);
    }
}

void SimulationView::renderStaticBodies(sf::RenderTarget& target, const std::vector<physics::StaticBody>& data) const
{
    sf::RectangleShape rect;
    rect.setFillColor(staticBodyColor);
    for (auto& body : data)
    {
        rect.setSize(ToVector2f(body.size));
        rect.setOrigin(ToVector2f(body.size / 2));
        rect.setPosition(ToVector2f(body.position));
        if (!body.isOrinted)
        {
            rect.setRotation(sf::radians(static_cast<float>(body.angle)));
        }
        target.draw(rect);
    }
}

} // namespace carom::graphics
