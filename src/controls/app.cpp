#include "controls/app.hpp"

#include "graphics/constants.hpp"

#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

namespace carom::controls {

App::App()
    : window_(
          sf::VideoMode({graphics::windowWidth, graphics::windowHeight}), graphics::windowTitle,
          sf::Style::Titlebar | sf::Style::Close
      )
    , cameraController_(simulationView_.getCamera())
{
    window_.setFramerateLimit(graphics::windowFPS);
}

void App::run()
{
    sf::Clock clock;
    while (window_.isOpen())
    {
        processEvents();
        update(clock.restart().asSeconds());
        render();
    }
}

void App::processEvents()
{
    while (const auto event = window_.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window_.close();
        }

        cameraController_.handleEvent(*event);
    }
}

void App::update(float dt)
{
    engine_.update(dt);
}

void App::render()
{
    window_.clear();
    simulationView_.render(window_);
    window_.display();
}

} // namespace carom::controls
