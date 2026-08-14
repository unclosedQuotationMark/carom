#pragma once

#include <cmath>

namespace carom::physics::math {

inline constexpr double epsilon = 1e-5;

template <typename T>
constexpr bool isZero(T x)
{
    return std::abs(x) < epsilon;
}

} // namespace carom::physics::math
