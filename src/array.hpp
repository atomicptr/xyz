/**
 * xyz: Collection of C++23 utilities
 * File: array.hpp - Lightweight dynamic sized array which doesn't allocate without you noticing
 *
 * Repository: https://github.com/atomicptr/xyz
 * License:    MIT
 */
#pragma once

#include <algorithm>
#include <cassert>
#include <initializer_list>

namespace xyz {

    template <typename T>
    class Array {
    public:
        Array(unsigned int length) {
            len = length;
            data = new T[len];
            clear();
        }

        Array(std::initializer_list<T> args) : Array(args.size()) {
            clear();

            auto index = 0u;
            for (auto arg : args) {
                this->data[index++] = arg;
            }
        }

        ~Array() {
            delete data;
        }

        unsigned int length() const {
            return len;
        }

        T& operator[](unsigned int index) {
            assert(index < len);
            return data[index];
        }

        const T& operator[](unsigned int index) const {
            assert(index < len);
            return data[index];
        }

        bool operator==(const Array<T>& other) const {
            if (length() != other.length()) {
                return false;
            }

            // length is equal and the start is equal? Same damn thing
            if (begin() == other.begin()) {
                return true;
            }

            for (auto i = 0u; i < len; i++) {
                if (data[i] != other[i]) {
                    return false;
                }
            }

            return true;
        }

        bool operator!=(const Array<T>& other) const {
            return !(*this == other);
        }

        void clear() {
            std::fill(data, data + len, T());
        }

        void resize(unsigned int new_size) {
            auto new_data = new T[new_size];
            std::fill(new_data, new_data + new_size, T());

            std::copy(data, data + len, new_data);

            delete data;

            len = new_size;
            data = new_data;
        }

        const T* begin() const {
            return data;
        }

        const T* end() const {
            return data + len;
        }

    private:
        T* data;
        unsigned int len;
    };
}
