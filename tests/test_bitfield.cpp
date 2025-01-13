#include "bitfield.hpp"

#include "base.hpp"

enum class Color {
    Red,
    Green,
    Blue
};

int main() {
    auto colors = xyz::BitField<Color>();

    expect_false(colors.has(Color::Red));
    expect_false(colors.has(Color::Blue));
    expect_false(colors.has(Color::Green));
    expect_equals(static_cast<xyz::BitField<Color>::backing_type>(0b000), colors.value());

    colors.enable(Color::Red);

    expect_true(colors.has(Color::Red));
    expect_false(colors.has(Color::Blue));
    expect_false(colors.has(Color::Green));
    expect_equals(static_cast<xyz::BitField<Color>::backing_type>(0b001), colors.value());

    colors.enable(Color::Blue);

    expect_true(colors.has(Color::Red));
    expect_true(colors.has(Color::Blue));
    expect_false(colors.has(Color::Green));
    expect_equals(static_cast<xyz::BitField<Color>::backing_type>(0b101), colors.value());

    colors.enable(Color::Green);

    expect_true(colors.has(Color::Red));
    expect_true(colors.has(Color::Blue));
    expect_true(colors.has(Color::Green));
    expect_equals(static_cast<xyz::BitField<Color>::backing_type>(0b111), colors.value());

    colors.enable(Color::Red);

    expect_true(colors.has(Color::Red));
    expect_true(colors.has(Color::Blue));
    expect_true(colors.has(Color::Green));
    expect_equals(static_cast<xyz::BitField<Color>::backing_type>(0b111), colors.value());

    colors.disable(Color::Red);

    expect_false(colors.has(Color::Red));
    expect_true(colors.has(Color::Blue));
    expect_true(colors.has(Color::Green));
    expect_equals(static_cast<xyz::BitField<Color>::backing_type>(0b110), colors.value());

    colors.disable(Color::Red);

    expect_false(colors.has(Color::Red));
    expect_true(colors.has(Color::Blue));
    expect_true(colors.has(Color::Green));
    expect_equals(static_cast<xyz::BitField<Color>::backing_type>(0b110), colors.value());

    return 0;
}
