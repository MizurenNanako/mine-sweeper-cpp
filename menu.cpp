#include "menu.hpp"

struct menu_impl
{
};

namespace cgt
{
#define impl ((struct menu_impl *)(_impl))
    menu_t::menu_t()
    {
        _impl = new menu_impl;
    }

    menu_t::~menu_t()
    {
        delete impl;
    }
}