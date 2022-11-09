#ifndef __board_hpp
#define __board_hpp

#include "util.hpp"
#include "cell_data.hpp"

namespace cgt
{
    class board_t
    {
    private:
        struct board_impl *impl;

    public:
        board_t(size_t w_ = 1, size_t h_ = 1);
        board_t(pos_t siz);
        ~board_t();
        cell::cell_t &operator()(size_t x, size_t y);
        void reset(size_t w_, size_t h_);
        void reset(pos_t siz);
    };
}

#endif // __board_hpp