/**
 * xyz: Collection of C++23 utilities
 * File: math.hpp - Collection of math utilities
 *
 * Repository: https://github.com/atomicptr/xyz
 * License:    MIT
 */
#pragma once

#include <cmath>

namespace xyz {
    const float epsilon = 0.000001f;

    template <typename T>
    concept Numeric = requires(T a, T b) {
        a + b;
        a > b;
        a < b;
        a == b;
    };

    template <Numeric T>
    inline T clamp(const T& value, const T& min, const T& max) {
        auto res = (value < min) ? min : value;
        return res > max ? max : res;
    }

    template <Numeric T>
    inline T min(const T& a, const T& b) {
        return (a < b) ? a : b;
    }

    template <Numeric T, Numeric... Args>
    inline T min(const T& first, const Args&... args) {
        return min(first, min(args...));
    }

    template <Numeric T>
    inline T max(const T& a, const T& b) {
        return (a > b) ? a : b;
    }

    template <Numeric T, Numeric... Args>
    inline T max(const T& first, const Args&... args) {
        return max(first, max(args...));
    }

    inline bool float_equals(float x, float y) {
        return std::abs(x - y) < epsilon;
    }

    inline float lerp(float start, float end, float amount) {
        return start + (end - start) * amount;
    }
}
