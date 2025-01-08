#include "array.hpp"

#include "base.hpp"

int main() {
    auto arr1 = xyz::array<int>(10);
    expect_equals(10u, arr1.length());
    expect_equals(0, arr1[5]);
    arr1[5] = 100;
    expect_equals(100, arr1[5]);

    auto arr2 = xyz::array{1, 2, 3, 4, 5};
    expect_equals(5u, arr2.length());
    expect_equals(3, arr2[2]);

    arr2.resize(10);
    expect_equals(10u, arr2.length());
    expect_equals(5, arr2[4]);
    expect_equals(0, arr2[9]);
    arr2[9] = 100;
    expect_equals(100, arr2[9]);

    auto index = 0;
    auto arr3 = xyz::array{0, 1, 4, 9, 16, 25};
    for (auto arg : arr3) {
        auto expected = index * index;
        expect_equals(expected, arg);

        index++;
    }

    expect_true(arr2 != arr3);
    expect_true((arr3 == xyz::array{0, 1, 4, 9, 16, 25}));

    return 0;
}
