#pragma once

#include "controls/camera_controller.hpp"
#include "graphics/simulation_view.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

namespace carom::controls {

class App
{
public:
    App();
    void run();

private:
    sf::RenderWindow window_;
    graphics::SimulationView simulationView_;
    CameraController cameraController_;

    void processEvents();
    void update();
    void render();
};

} // namespace carom::controls
