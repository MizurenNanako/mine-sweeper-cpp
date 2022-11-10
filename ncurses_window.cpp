#include "ncurses.hpp"

struct window_impl
{
};

namespace cgt
{
#define impl ((struct window_impl *)(_impl))
    using my = ncurses_t::window_t;
    my::window_t()
    {
        _impl = new window_impl;
    }
    my::~window_t()
    {
        delete impl;
    }
}