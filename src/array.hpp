#pragma once

#include <cassert>
#include <initializer_list>
#include <algorithm>

namespace xyz {

    template<typename T>
    class array {
    public:
        array(unsigned int length) {
            len = length;
            data = new T[len];
            clear();
        }

        array(std::initializer_list<T> args) : array(args.size()) {
            clear();
            
            auto index = 0u;
            for (auto arg : args) {
                this->data[index++] = arg;
            }
        }

        ~array() {
            delete data;
        }

        unsigned int length() const {
            return len;
        }

        T* raw() {
            return data;
        }

        T& operator[](unsigned int index) {
            assert(index < len);
            return data[index];
        }

        const T& operator[](unsigned int index) const {
            assert(index < len);
            return data[index];
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
