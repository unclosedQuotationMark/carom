#pragma once

#include "physics/types/vector2d.hpp"

#include <SFML/System/Vector2.hpp>

namespace carom::graphics {

constexpr sf::Vector2f ToVector2f(physics::Vector2D vec) noexcept
{
    return sf::Vector2f(static_cast<float>(vec.x), static_cast<float>(vec.y));
}
} // namespace carom::graphics
