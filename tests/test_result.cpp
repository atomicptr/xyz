#include "result.hpp"
#include "vector2.hpp"

#include "base.hpp"

int main() {
    using IntRes = xyz::Result<int>;
    
    expect_true(IntRes::error("test").has_error());
    expect_false(IntRes::ok(100).has_error());

    expect_true(IntRes::ok(100).is_ok());
    expect_false(IntRes::ok(100).has_error());

    expect_equals(1337, IntRes::ok(1337).value());

    auto maybe_vec = xyz::Result<xyz::Vector2>::ok({13.37f, 42.0f});
    expect_true(maybe_vec.is_ok());
    expect_equals(13.37f, maybe_vec->x);

    expect_equals((xyz::Vector2 {13.37f, 42.0f}), maybe_vec.value());

    using DoubleStringResult = xyz::Result<const char*, const char*>;

    expect_true(DoubleStringResult::ok("test").is_ok());
    expect_true(DoubleStringResult::error("test").has_error());

    expect_equals("error", xyz::Result<const char*>::error("error").error_value());
    expect_equals("ok", xyz::Result<const char*>::ok("ok").value());

    return 0;
}
