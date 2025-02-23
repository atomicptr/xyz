#include "pool.hpp"

#include "base.hpp"
#include "tests/buster.hpp"

struct Test {
    int x;
    int y;

    bool alive;

    bool is_alive() const {
        return alive;
    }

    void pool_init(int x, int y) {
        this->x = x;
        this->y = y;
        this->alive = true;
    }

    void kill() {
        alive = false;
    }
};

int main() {
    auto pool = xyz::Pool<Test, 3>();

    expect_true(pool.can_create());

    auto& t1 = pool.create(5, 100);
    expect_equals(5, t1.x);
    expect_equals(100, t1.y);
    expect_true(t1.is_alive());

    expect_true(pool.can_create());

    auto& t2 = pool.create(13, 37);
    expect_equals(13, t2.x);
    expect_equals(37, t2.y);
    expect_true(t2.is_alive());

    auto& t3 = pool.create(1, 2);
    expect_true(t3.is_alive());

    expect_false(pool.can_create());

    t2.alive = false;

    expect_true(pool.can_create());

    auto counter = 0;

    for (auto& item : pool.items()) {
        counter++;
        expect_true(item.is_alive());
    }

    expect_equals(2, counter);

    t2 = pool.create(42, 42);
    expect_equals(42, t2.x);
    expect_equals(42, t2.y);
    expect_true(t2.is_alive());

    expect_false(pool.can_create());

    return 0;
}
