#include "controls/camera_controller.hpp"

#include "controls/constants.hpp"
#include "graphics/constants.hpp"

namespace carom::controls {

CameraController::CameraController(sf::View& camera)
    : camera_(camera)
{
}

void CameraController::handleEvent(const sf::Event& event)
{
    if (const auto* mouseButtonPressed = event.getIf<sf::Event::MouseButtonPressed>())
    {
        if (mouseButtonPressed->button == sf::Mouse::Button::Right)
        {
            isDragging_ = true;
            lastMousePos_ = mouseButtonPressed->position;
        }
    }
    if (const auto* mouseButtonReleased = event.getIf<sf::Event::MouseButtonReleased>())
    {
        if (mouseButtonReleased->button == sf::Mouse::Button::Right)
        {
            isDragging_ = false;
        }
    }
    if (const auto* mouseMoved = event.getIf<sf::Event::MouseMoved>())
    {
        if (isDragging_)
        {
            move(mouseMoved->position);
        }
    }
    if (const auto* scroll = event.getIf<sf::Event::MouseWheelScrolled>())
    {
        if (scroll->delta)
        {
            zoom(scroll->delta, scroll->position);
        }
    }
}

void CameraController::move(sf::Vector2i pos)
{
    sf::Vector2i delta = lastMousePos_ - pos;
    lastMousePos_ = pos;
    camera_.move({delta.x * zoomFactor_, delta.y * zoomFactor_});
}

void CameraController::zoom(float delta, sf::Vector2i mousePos)
{
    float factor = 1.f;
    if (delta > 0.f)
    {
        factor = zoomUpFactor;
    }
    else if (delta < 0.f)
    {
        factor = zoomDownFactor;
    }
    zoomFactor_ *= factor;

    sf::Vector2f oldSize = camera_.getSize();
    camera_.zoom(factor);
    sf::Vector2f newSize = camera_.getSize();

    sf::FloatRect viewport = camera_.getViewport();

    float viewX = static_cast<float>(graphics::windowWidth) * viewport.position.x;
    float viewY = static_cast<float>(graphics::windowHeight) * viewport.position.y;
    float viewWidth = static_cast<float>(graphics::windowWidth) * viewport.size.x;
    float viewHeight = static_cast<float>(graphics::windowHeight) * viewport.size.y;

    float relX = (static_cast<float>(mousePos.x) - viewX) / viewWidth - 0.5f;
    float relY = (static_cast<float>(mousePos.y) - viewY) / viewHeight - 0.5f;

    sf::Vector2f centerOffset(relX * (oldSize.x - newSize.x), relY * (oldSize.y - newSize.y));

    camera_.setCenter(camera_.getCenter() + centerOffset);
}

} // namespace carom::controls
