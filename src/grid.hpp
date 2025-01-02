#pragma once

#include <cassert>
#include <vector>

namespace xyz {
    inline unsigned int grid_index(unsigned int width, unsigned int x, unsigned int y) {
        return (y * width) + x;
    }
    
    template<typename T>
    class grid {
    public:
        grid(unsigned int width, unsigned int height) : grid(width, height, T()) {}

        grid(unsigned int width, unsigned int height, T default_value) : width(width), height(height) {
            data.reserve(width * height);
            for (unsigned int i = 0; i < width * height; i++) {
                data.push_back(default_value);
            }
        }

        const T& get(unsigned int x, unsigned int y) const {
            assert(x <= width);
            assert(y <= height);
            return data[grid_index(width, x, y)];
        }

        void set(unsigned int x, unsigned int y, T value) {
            assert(x <= width);
            assert(y <= height);
            data[grid_index(width, x, y)] = value;
        }
    private:
        std::vector<T> data;
        unsigned int width;
        unsigned int height;
    };
}
