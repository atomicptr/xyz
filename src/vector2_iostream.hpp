/**
 * xyz: Collection of C++23 utilities
 * File: vector2_iostream.hpp - Enabling you to print xyz::Vector2 using std::ostream
 *
 * Repository: https://github.com/atomicptr/xyz
 * License:    MIT
 */
#pragma once

#include <iostream>

#include "vector2.hpp"

inline std::ostream& operator<<(std::ostream& os, const xyz::Vector2& vec) {
    os << "Vector2 { x = " << vec.x << ", y = " << vec.y << " }";
    return os;
}
