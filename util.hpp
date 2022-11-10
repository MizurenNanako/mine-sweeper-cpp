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
    constexpr inline pos_t operator+(pos_t lhs, pos_t rhs)
    {
        return pos_t{lhs.first + rhs.first, lhs.second + rhs.second};
    }
    constexpr inline pos_t operator-(pos_t lhs, pos_t rhs)
    {
        return pos_t{lhs.first - rhs.first, lhs.second - rhs.second};
    }
}

#endif // __util_hpp
