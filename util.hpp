#ifndef __util_hpp
#define __util_hpp

#include <stddef.h>
#include <array>
#include <vector>
#include <string>
#include <functional>

namespace cgt
{
    using pos_t = std::pair<int, int>;
    template <typename Any>
    using func = std::function<Any>;
    constexpr std::array<pos_t, 8>
        near8 = {
            pos_t{-1, -1},
            {0, -1},
            {1, -1},
            {-1, 0},
            {1, 0},
            {-1, 1},
            {0, 1},
            {1, 1},
    };
    constexpr std::array<pos_t, 4>
        near4 = {pos_t{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
}

constexpr inline cgt::pos_t operator+(cgt::pos_t lhs, cgt::pos_t rhs) { return cgt::pos_t{lhs.first + rhs.first, lhs.second + rhs.second}; }
constexpr inline cgt::pos_t operator-(cgt::pos_t lhs, cgt::pos_t rhs) { return cgt::pos_t{lhs.first - rhs.first, lhs.second - rhs.second}; }
constexpr inline cgt::pos_t operator+(cgt::pos_t lhs, int val) { return cgt::pos_t{lhs.first + val, lhs.second + val}; }
constexpr inline cgt::pos_t operator-(cgt::pos_t lhs, int val) { return cgt::pos_t{lhs.first - val, lhs.second - val}; }
constexpr inline cgt::pos_t operator*(cgt::pos_t lhs, int val) { return cgt::pos_t{lhs.first * val, lhs.second * val}; }
constexpr inline cgt::pos_t operator/(cgt::pos_t lhs, int val) { return cgt::pos_t{lhs.first / val, lhs.second / val}; }

#endif // __util_hpp
