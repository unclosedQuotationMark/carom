#pragma once

namespace carom::physics {

using real = double;

constexpr real operator""_r(long double val)
{
    return static_cast<real>(val);
}

constexpr real operator""_r(unsigned long long val)
{
    return static_cast<real>(val);
}

} // namespace carom::physics
