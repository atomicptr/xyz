/**
 * xyz: Collection of C++23 utilities
 * File: grid.hpp - A simple grid data type
 *
 * Repository: https://github.com/atomicptr/xyz
 * License:    MIT
 */
#pragma once

#include <cassert>

#ifndef XYZ_GRID_NO_ARRAY
    #include "array.hpp"
#endif

namespace xyz {
    inline unsigned int grid_index(unsigned int width, unsigned int x, unsigned int y) {
        return (y * width) + x;
    }

    template <typename T, typename BackingType = Array<T>>
    class Grid {
    public:
        Grid(unsigned int width, unsigned int height) : Grid(width, height, T()) {}

        Grid(unsigned int width, unsigned int height, T default_value) :
            data(width * height), width(width), height(height) {
            assert(width >= 1);
            assert(height >= 1);

            for (auto i = 0u; i < width * height; i++) {
                data[i] = default_value;
            }
        }

        inline T& operator[](unsigned int x, unsigned int y) {
            assert(x < width);
            assert(y < height);
            return data[grid_index(width, x, y)];
        }

        inline const T& operator[](unsigned int x, unsigned int y) const {
            assert(x < width);
            assert(y < height);
            return data[grid_index(width, x, y)];
        }

    private:
        BackingType data;
        unsigned int width;
        unsigned int height;
    };
}
