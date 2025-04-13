#include "math.hpp"

#include "base.hpp"
#include "tests/buster.hpp"

#include <cassert>

int main() {
    // clamp
    expect_equals(5, xyz::clamp(5, 0, 10));
    expect_equals(10, xyz::clamp(5, 10, 20));
    expect_equals(3, xyz::clamp(5, 0, 3));
    expect_equals(5, xyz::clamp(5, 0, 5));
    expect_equals(5, xyz::clamp(5, 5, 8));

    // min
    expect_equals(5, xyz::min(10, 5));
    expect_equals(5, xyz::min(10, 100, 5));
    expect_equals(-100, xyz::min(10, -100, 5));
    expect_equals(-5, xyz::min(10, 5, 0, 100, -5, 20));
    expect_equals(5, xyz::min(5, 5));
    expect_equals(3.14, xyz::min(3.14, 3.15));

    // max
    expect_equals(10, xyz::max(10, 5));
    expect_equals(100, xyz::max(10, 100, 5));
    expect_equals(10, xyz::max(10, -100, 5));
    expect_equals(100, xyz::max(10, 5, 0, 100, -5, 20));
    expect_equals(5, xyz::max(5, 5));
    expect_equals(3.15, xyz::max(3.14, 3.15));

    // lerp
    auto value = xyz::lerp(0.0f, 10.0f, 0.0f);
    expect_equals(0.0f, value);
    value = xyz::lerp(0.0f, 10.0f, 1.0f);
    expect_equals(10.0f, value);
    value = xyz::lerp(0.0f, 10.0f, 0.5f);
    expect_equals(5.0f, value);
    value = xyz::lerp(-5.0f, 5.0f, 0.5f);
    expect_equals(0.0f, value);
    value = xyz::lerp(0.0f, 10.0f, 0.33f);
    expect_equals(3.3f, value);
    value = xyz::lerp(7.0f, 7.0f, 0.5f);
    expect_equals(7.0f, value);
    value = xyz::lerp(0.0f, 10.0f, 1.5f);
    expect_equals(15.0f, value);
    value = xyz::lerp(0.0f, 10.0f, -0.5f);
    expect_equals(-5.0f, value);

    // float_equals
    expect_true(xyz::float_equals(0.3f, 0.1f + 0.2f));

    // sign
    expect_true(xyz::sign(-1234.0f) < 0.0f);
    expect_true(xyz::sign(1234.0) > 0.0);
    expect_true(xyz::sign(555) > 0.0);
    expect_true(xyz::sign(-555) < 0);
    expect_true(xyz::sign(0) == 0);

    return 0;
}
