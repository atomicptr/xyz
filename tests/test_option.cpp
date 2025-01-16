#include "option.hpp"
#include "vector2.hpp"

#include "base.hpp"

int main() {
    using IntOpt = xyz::Option<int>;
    
    expect_true(IntOpt::none().is_none());
    expect_false(IntOpt::some(100).is_none());

    expect_true(IntOpt::some(100).is_some());
    expect_false(IntOpt::some(100).is_none());

    expect_equals(1337, IntOpt::some(1337).value());

    auto maybe_vec = xyz::Option<xyz::Vector2>::some({13.37f, 42.0f});
    expect_true(maybe_vec.is_some());
    expect_equals(13.37f, maybe_vec->x);

    expect_equals((xyz::Vector2 {13.37f, 42.0f}), maybe_vec.value());

    return 0;
}
