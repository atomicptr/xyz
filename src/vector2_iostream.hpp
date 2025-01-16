#pragma once

#include <iostream>

#include "vector2.hpp"

inline std::ostream& operator<<(std::ostream& os, const xyz::Vector2& vec) {
    os << "Vector2 { x = " << vec.x << ", y = " << vec.y << " }";
    return os;
}
