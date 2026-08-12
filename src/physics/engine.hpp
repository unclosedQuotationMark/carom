#pragma once

#include "physics/types/real.hpp"

namespace carom::physics {

class Engine
{
public:
    void update(real dt);
};

} // namespace carom::physics
