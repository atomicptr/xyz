#pragma once

#include "math.hpp"
#include <iostream>
#include <assert.h>

#define expect_equals(expected, actual) expect_equals_impl((expected), (actual), __FILE__, __LINE__)

template<typename T>
inline void expect_equals_impl(T expected, T actual, const char* file, int line) {
    auto is_equals = expected == actual;

    if (!is_equals) {
        std::cout << "Expected '" << actual << "' to be '" << expected << "' at " << file << ":" << line << std::endl;
    }

    assert(is_equals);
}

template<>
inline void expect_equals_impl(float expected, float actual, const char* file, int line) {
    auto is_equals = xyz::float_equals(expected, actual);
    
    if (!is_equals) {
        std::cout << "Expected '" << actual << "' to be '" << expected << "' at " << file << ":" << line << std::endl;
    }

    assert(is_equals);
}

#define expect_true(value) expect_true_impl(value, __FILE__, __LINE__)

inline void expect_true_impl(bool actual, const char* file, int line) {
    if (!actual) {
        std::cout << "Expected value to be true at " << file << line << std::endl;
    }

    assert(actual);
}

#define expect_false(value) expect_false_impl(value, __FILE__, __LINE__)

inline void expect_false_impl(bool actual, const char* file, int line) {
    if (actual) {
        std::cout << "Expected value to be false at " << file << line << std::endl;
    }

    assert(!actual);
}
