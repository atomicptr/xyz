#include "vector2.hpp"

#include  "base.hpp"

using namespace xyz;

int main() {
    expect_equals(Vector2::one(), Vector2::zero() + Vector2::one());
    expect_equals(Vector2::one(), Vector2::zero() + 1.0f);
    expect_equals(Vector2::zero(), Vector2::one() - Vector2::one());
    expect_equals(Vector2::zero(), Vector2::one() - 1.0f);
    expect_equals((Vector2 { 3.0f, 6.0f}), (Vector2::one() * Vector2 { 3.0f, 6.0f }));
    expect_equals((Vector2 { 2.0f, 2.0f }), Vector2::one() * 2.0f);
    expect_equals((Vector2 { 0.5f, 1.0f}), (Vector2::one() / Vector2 { 2.0f, 1.0f }));
    expect_equals((Vector2 { 0.5f, 0.5f }), Vector2::one() / 2.0f);
    expect_true(Vector2::one() == Vector2::one());
    expect_false(Vector2::one() != Vector2::one());

    auto vec = Vector2::one();
    vec = { 13.0f, 37.0f };
    expect_equals((Vector2 {13.0f, 37.0f}), vec);

    expect_equals(1.0f, Vector2::up().length());
    expect_equals(3.0f, (Vector2::up() * 3.0f).length());
    expect_equals(1.0f, (Vector2 {13.0f, 37.0f}).normalize().length());

    expect_equals(2.0f, (Vector2{1.0f, 1.0f}).dot_product((Vector2{1.0f, 1.0f})));
    expect_equals(0.0f, (Vector2{1.0f, 0.0f}).dot_product((Vector2{0.0f, 1.0f})));
    expect_equals(-1.0f, (Vector2{1.0f, 0.0f}).dot_product((Vector2{-1.0f, 0.0f})));

    expect_equals(0.0f, (Vector2{1.0f, 0.0f}).cross_product((Vector2{1.0f, 0.0f})));
    expect_equals(1.0f, (Vector2{1.0f, 0.0f}).cross_product((Vector2{0.0f, 1.0f})));
    expect_equals(-1.0f, (Vector2{0.0f, 1.0f}).cross_product((Vector2{1.0f, 0.0f})));

    expect_equals(2.0f, (Vector2{1.0f, 1.0f}).distance_to_squared((Vector2{2.0f, 2.0f})));
    expect_equals(0.0f, (Vector2{0.0f, 0.0f}).distance_to_squared((Vector2{0.0f, 0.0f})));
    expect_equals(18.0f, (Vector2{2.0f, 1.0f}).distance_to_squared((Vector2{5.0f, 4.0f})));

    expect_equals(sqrt(2.0f), (Vector2{1.0f, 1.0f}).distance_to((Vector2{2.0f, 2.0f})));
    expect_equals(0.0f, (Vector2{0.0f, 0.0f}).distance_to((Vector2{0.0f, 0.0f})));
    expect_equals(sqrt(18.0f), (Vector2{2.0f, 1.0f}).distance_to((Vector2{5.0f, 4.0f})));

    auto normalized = (Vector2{3.0f, 4.0f}).normalize();
    expect_equals(1.0f, normalized.length());
    expect_equals((Vector2{0.6f, 0.8f}), normalized); // Assuming precision for comparison
    expect_equals((Vector2{1.0f, 0.0f}), (Vector2{5.0f, 0.0f}).normalize());

    expect_equals((Vector2 { 4.0f, 0.0f }), (Vector2 { 1.0f, 0.f }).move_towards((Vector2 {10.0f, 0.0f}), 3.0f));

    expect_equals((Vector2{2.0f, 3.0f}), (Vector2{1.0f, 4.0f}).clamp((Vector2{2.0f, 2.0f}), (Vector2{3.0f, 3.0f})));
    expect_equals((Vector2{2.0f, 2.0f}), (Vector2{1.0f, 1.0f}).clamp((Vector2{2.0f, 2.0f}), (Vector2{3.0f, 3.0f})));
    expect_equals((Vector2{3.0f, 3.0f}), (Vector2{4.0f, 4.0f}).clamp((Vector2{2.0f, 2.0f}), (Vector2{3.0f, 3.0f})));

    return 0;
}
