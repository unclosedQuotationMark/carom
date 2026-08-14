#pragma once

#include "physics/types/real.hpp"

#include <algorithm>
#include <numbers>
#include <random>
#include <vector>

namespace carom::physics {

class RandomGenerator
{
public:
    RandomGenerator(const RandomGenerator&) = delete;
    RandomGenerator& operator=(const RandomGenerator&) = delete;

    static RandomGenerator& getInstance()
    {
        static RandomGenerator instance;
        return instance;
    }

    real getReal(real min, real max)
    {
        std::uniform_real_distribution<real> dist(min, max);
        return dist(gen);
    }

    real getAngle()
    {
        std::uniform_real_distribution<real> dist(0, 2 * std::numbers::pi);
        return dist(gen);
    }

    template <typename T>
    void shuffle(std::vector<T>& vec)
    {
        std::shuffle(vec.begin(), vec.end(), gen);
    }

private:
    std::mt19937 gen;

    RandomGenerator()
        : gen(std::random_device{}())
    {
    }

    ~RandomGenerator() = default;
};

} // namespace carom::physics
