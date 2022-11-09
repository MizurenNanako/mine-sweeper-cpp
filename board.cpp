#include "board.hpp"
#include <vector>
using std::vector;

struct board_impl
{
    size_t w, h;
    vector<cgt::cell::cell_t> data;

    board_impl(size_t w_, size_t h_)
        : w{w_}, h{h_}
    {
        data.resize(w_ * h_ + 1);
    }
    inline cgt::cell::cell_t &operator()(size_t x, size_t y)
    {
        return data[y * w + x];
    }
};

namespace cgt
{
#define impl ((struct board_impl *)(_impl))
    board_t::board_t(size_t w_, size_t h_)
    {
        _impl = new board_impl(w_, h_);
    }

    board_t::board_t(pos_t siz) : board_t(siz.first, siz.second) {}

    board_t::~board_t()
    {
        delete impl;
    }

    cell::cell_t &board_t::operator()(size_t x, size_t y)
    {
        return (*impl)(x, y);
    }

    void board_t::reset(size_t w_, size_t h_)
    {
        impl->data.resize(w_ * h_ + 1);
    }

    void board_t::reset(pos_t siz)
    {
        impl->data.resize(siz.first * siz.second + 1);
    }
}