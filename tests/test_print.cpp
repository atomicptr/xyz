#include "print.hpp"

#include "base.hpp"

#include <sstream>

int main() {
    auto ss = std::stringstream {};

    xyz::print(ss, "Hello {}!", "World");

    expect_equals(ss.str(), "Hello World!");

    return 0;
}
