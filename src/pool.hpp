/**
 * xyz: Collection of C++23 utilities
 * File: pool.hpp - Generic object pool implementation
 *
 * Repository: https://github.com/atomicptr/xyz
 * License:    MIT
 */
#pragma once

#include <array>
#include <cassert>
#include <concepts>
#include <ranges>
#include <stdexcept>

namespace xyz {
    template <typename T, typename... Args>
    concept PoolItem = requires(T a, Args&&... args) {
        { a.is_alive() } -> std::convertible_to<bool>;
    };

    template <PoolItem T, std::size_t N>
    class Pool {
    public:
        Pool() {
            for (std::size_t i = 0; i < N; i++) {
                data[i] = T {};
            }
        }

        bool can_create() const {
            for (std::size_t i = 0; i < N; i++) {
                if (!data[i].is_alive()) {
                    return true;
                }
            }

            return false;
        }

        template <typename... Args>
        T& create(Args&&... args) {
            static_assert(
                requires(T t, Args&&... a) { t.pool_init(std::forward<Args>(a)...); },
                "Type T must have an init method compatible with the provided arguments"
            );

            for (std::size_t i = 0; i < N; i++) {
                if (!data[i].is_alive()) {
                    data[i].pool_init(std::forward<Args>(args)...);
                    assert(data[i].is_alive());
                    return data[i];
                }
            }

            throw std::runtime_error("pool is emtpy");
        }

        auto items() {
            return data | std::ranges::views::filter([](T& item) { return item.is_alive(); });
        }

    private:
        std::array<T, N> data;
    };
}
