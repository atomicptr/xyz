/**
 * xyz: My custom C++ standard library
 *
 * Repository: https://github.com/atomicptr/xyz
 * License:    MIT
 */
#pragma once

#include <cassert>

namespace xyz {

    template<typename T>
    class Option {
    public:
        static Option<T> some(T value) {
            return Option(value);
        }

        static Option<T> none() {
            return Option();
        }

        bool is_some() const {
            return has_value;
        }

        bool is_none() const {
            return !has_value;
        }

        const T& value() const {
            assert(has_value);
            return data;
        }

        const T& or_else(T value) const {
            if (has_value) {
                return data;
            }
            return value;
        }

        const T* operator->() const {
            assert(has_value);
            return &data;
        }
    private:
        T data;
        bool has_value;

        Option() : has_value(false) {}
        Option(T data) : data(data), has_value(true) {}
    };
}
