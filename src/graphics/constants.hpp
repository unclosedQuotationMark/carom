#pragma once

#include <SFML/Graphics/Color.hpp>

namespace carom::graphics {

inline constexpr unsigned int windowWidth{800};
inline constexpr unsigned int windowHeight{600};
inline constexpr const char* windowTitle{"Carom"};
inline constexpr unsigned int windowFPS{60};

inline constexpr sf::Color backGroundColor{sf::Color::Black};
inline constexpr sf::Color particleColor{sf::Color::Blue};

} // namespace carom::graphics
