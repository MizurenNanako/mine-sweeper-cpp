#include "menu.hpp"
#include "ncurses.hpp"
#include <list>

using item_t = cgt::menu_t::menu_item_t;

struct menu_impl
{
    cgt::ncurses_t::window_t win;
    std::list<item_t> options;
    size_t maxwidth = 0;
};

inline constexpr bool operator<(
    const item_t &lhs, const item_t &rhs) { return lhs.name < rhs.name; }

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
    menu_t &menu_t::add_item(const menu_item_t &item)
    {
        impl->options.push_back(item);
        impl->maxwidth = item.name.length() > impl->maxwidth
                             ? item.name.length()
                             : impl->maxwidth;
        return *this;
    }
    void menu_t::sort()
    {
        impl->options.sort();
    }
}