/**
 * xyz: Collection of C++23 utilities
 * File: bitfield.hpp - Wrapping class for handling bitfields using enum classes
 *
 * Repository: https://github.com/atomicptr/xyz
 * License:    MIT
 */
#pragma once

#include <cstdint>
#include <type_traits>

namespace xyz {
    template <typename T, typename BackingType = uint32_t>
        requires std::is_enum_v<T> && std::is_integral_v<BackingType>
    class BitField {
    private:
        BackingType bits;

        static constexpr BackingType bitPosition(T value) {
            return static_cast<BackingType>(value);
        }

    public:
        using backing_type = BackingType;

        BitField() : bits(0) {}

        bool has(T value) const {
            return (bits & (1u << bitPosition(value))) != 0;
        }

        void enable(T value) {
            bits |= (1u << bitPosition(value));
        }

        void disable(T value) {
            bits &= ~(1u << bitPosition(value));
        }

        void toggle(T value) {
            if (has(value)) {
                disable(value);
                return;
            }
            enable(value);
        }

        void set_when(bool condition, T value) {
            if (condition) {
                enable(value);
                return;
            }
            disable(value);
        }

        BackingType value() const {
            return bits;
        }
    };
}
