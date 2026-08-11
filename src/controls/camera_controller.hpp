#pragma once

#include <SFML/Graphics/View.hpp>
#include <SFML/Window/Event.hpp>

namespace carom::controls {

class CameraController
{
public:
    CameraController(sf::View& camera);
    void handleEvent(const sf::Event& event);

private:
    sf::View& camera_;

    bool isDragging_{false};
    sf::Vector2i lastMousePos_{};
    float zoomFactor_{1.f};

    void move(sf::Vector2i pos);
    void zoom(float delta, sf::Vector2i mousePos);
};

} // namespace carom::controls
