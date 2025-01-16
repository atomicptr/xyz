/**
 * xyz: My custom C++ standard library
 *
 * Repository: https://github.com/atomicptr/xyz
 * License:    MIT
 */
#pragma once

#include <cstdint>
#include <type_traits>

namespace xyz {
    template<typename T, typename BackingType = uint32_t>
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

        BackingType value() const {
            return bits;
        }
    };
}
