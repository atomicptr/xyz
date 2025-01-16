/**
 * xyz: My custom C++ standard library
 *
 * Repository: https://github.com/atomicptr/xyz
 * License:    MIT
 */
#pragma once

#include <cassert>

namespace xyz {

    template<typename T, typename Err = const char*>
    class Result {
    public:
        static Result<T, Err> ok(T data) {
            return Result(data);
        }

        static Result<T, Err> error(Err error) {
            return Result(error, true);
        }

        bool is_ok() const {
            return !has_err;
        }

        bool has_error() const {
            return has_err;
        }

        const Err& error_value() const {
            assert(has_err);
            return err;
        }

        const T& value() const {
            assert(!has_err);
            return data;
        }

        const T& or_else(T value) const {
            if (!has_err) {
                return data;
            }
            return value;
        }

        const T* operator->() const {
            assert(!has_err);
            return &data;
        }
    private:
        T data;
        Err err;
        bool has_err;

        Result(T data) : data(data), has_err(false) {}
        Result(Err err, bool has_error) : err(err), has_err(has_error) {}
    };
}
