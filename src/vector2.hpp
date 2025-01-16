#pragma once

#include <iostream>
#include <math.h>

#include "math.hpp"

namespace xyz {
    struct Vector2 {
        float x;
        float y;

        inline static Vector2 zero() {
            return { 0.0f, 0.0f };
        }

        inline static Vector2 one() {
            return { 1.0f, 1.0f };
        }

        inline static Vector2 up() {
            return { 0.0f, -1.0f };
        }

        inline static Vector2 down() {
            return { 0.0f, 1.0f };
        }

        inline static Vector2 left() {
            return { -1.0f, 0.0f };
        }

        inline static Vector2 right() {
            return { 1.0f, 0.0f };
        }

        inline const Vector2 operator+(const Vector2& other) const {
            return { x + other.x, y + other.y };
        }

        inline const Vector2 operator+(float value) const {
            return { x + value, y + value };
        }

        inline const Vector2 operator-(const Vector2& other) const {
            return { x - other.x, y - other.y };
        }

        inline const Vector2 operator-(float value) const {
            return { x - value, y - value };
        }

        inline const Vector2 operator*(const Vector2& other) const {
            return { x * other.x, y * other.y };
        }

        inline const Vector2 operator*(float value) const {
            return { x * value, y * value };
        }

        inline const Vector2 operator/(const Vector2& other) const {
            return { x / other.x, y / other.y };
        }

        inline const Vector2 operator/(float value) const {
            return {x / value, y / value};
        }

        inline bool operator==(const Vector2& other) const {
            return float_equals(x, other.x) && float_equals(y, other.y);
        }

        inline bool operator!=(const Vector2& other) const {
            return !(*this == other);
        }

        inline Vector2& operator=(const Vector2& other) {
            if (this == &other) {
                return *this;
            }
            
            x = other.x;
            y = other.y;

            return *this;
        }

        inline Vector2& operator+=(const Vector2& other) {
            *this = *this + other;
            return *this;
        }

        inline Vector2& operator+=(float value) {
            *this = *this + value;
            return *this;
        }

        inline Vector2& operator-=(const Vector2& other) {
            *this = *this - other;
            return *this;
        }

        inline Vector2& operator-=(float value) {
            *this = *this - value;
            return *this;
        }

        inline Vector2& operator*=(const Vector2& other) {
            *this = *this * other;
            return *this;
        }

        inline Vector2& operator*=(float value) {
            *this = *this * value;
            return *this;
        }

        inline Vector2& operator/=(const Vector2& other) {
            *this = *this / other;
            return *this;
        }

        inline Vector2& operator/=(float value) {
            *this = *this / value;
            return *this;
        }

        inline float length_squared() const {
            return x * x + y * y;
        }

        inline float length() const {
            return sqrtf(length_squared());
        }

        inline float dot_product(const Vector2& other) const {
            return x * other.x + y * other.y;
        }

        inline float cross_product(const Vector2& other) const {
            return x * other.y - y * other.x;
        }

        inline float distance_to_squared(const Vector2& other) const {
            auto x = this->x - other.x;
            auto y = this->y - other.y;
            return x * x + y * y;
        }

        inline float distance_to(const Vector2& other) const {
            return sqrtf(distance_to_squared(other));
        }

        inline Vector2 normalize() const {
            auto len = length();
            return len > 0.0f ? *this * (1.0f / len) : Vector2::zero();
        }

        inline Vector2 move_towards(const Vector2& target, float delta) const {
            auto dest = target - *this;
            auto len = dest.length();
            return len <= delta || len < epsilon
                ? target
                : *this + (dest / len * delta);
        }

        inline Vector2 clamp(const Vector2& min, const Vector2& max) const {
            return { xyz::clamp(x, min.x, max.x), xyz::clamp(y, min.y, max.y) };
        }

        inline Vector2 clamp(float min, float max) const {
            return { xyz::clamp(x, min, max), xyz::clamp(y, min, max) };
        }
    };
}

inline std::ostream& operator<<(std::ostream& os, const xyz::Vector2& vec) {
    os << "Vector2 { x = " << vec.x << ", y = " << vec.y << " }";
    return os;
}
