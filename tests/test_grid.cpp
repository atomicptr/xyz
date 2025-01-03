#include "grid.hpp"

#include "base.hpp"

struct Test {
    int x;
    int y;
};

int main() {
    auto g = xyz::grid<int>(10, 10);
    expect_equals(0, (g[3, 3]));
    g[3, 3] = 100;
    expect_equals(100, (g[3, 3]));


    auto g2 = xyz::grid<Test>(5, 5);
    expect_equals(0, (g2[1, 1].x)); // sub values are setup using default values
    g2[1, 1] = {10, 12};
    expect_equals(10, (g2[1, 1]).x);
    expect_equals(12, (g2[1, 1]).y);

    auto g3 = xyz::grid<Test*>(5, 5);
    expect_equals((Test*)nullptr, (g3[1, 1]));

    return 0;
}
