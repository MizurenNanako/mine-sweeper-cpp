#include "ncurses.hpp"
#include <ncurses.h>
#include <string.h>

typedef WINDOW window_impl;

namespace cgt
{
#define impl ((window_impl *)(_impl))
    using me = ncurses_t::window_t;
    me::window_t(pos_t siz, pos_t pos)
    {
        _impl = ::newwin(siz.second, siz.first, pos.second, pos.first);
    }
    me::window_t(const me &rhs)
    {
        _impl = ::dupwin((window_impl *)(rhs._impl));
    }
    me::~window_t()
    {
        ::delwin(impl);
    }
    pos_t me::size()
    {
        return {impl->_maxx, impl->_maxy};
    }
    void me::move_to(pos_t pos)
    {
        ::mvwin(impl, pos.second, pos.first);
    }
    void me::resize(pos_t siz)
    {
        ::wresize(impl, siz.second, siz.first);
    }
    void me::clear()
    {
        ::wclear(impl);
    }
    void me::refresh()
    {
        ::wrefresh(impl);
    }
    void me::draw_str(const char *cstr, pos_t pos)
    {
        mvwaddstr(impl, pos.second, pos.first, cstr);
    }
    void me::draw_ch(char ch, pos_t pos)
    {
        mvwaddch(impl, pos.second, pos.first, ch);
    }
    void me::draw_hline(char ch, pos_t pos, size_t len)
    {
        mvwhline(impl, pos.second, pos.first, ch, len);
    }
    void me::draw_vline(char ch, pos_t pos, size_t len)
    {
        mvwvline(impl, pos.second, pos.first, ch, len);
    }
    void me::draw_box(char ch, pos_t LT, pos_t RD)
    {
        pos_t B = RD - LT;
        mvwhline(impl, LT.second, LT.first, ch, B.first);     // top
        mvwhline(impl, RD.second, LT.first, ch, B.first + 1); // down
        mvwvline(impl, LT.second, LT.first, ch, B.second);    // left
        mvwvline(impl, LT.second, RD.first, ch, B.second);    // right
    }
    void me::draw_border()
    {
        ::box(impl, '|', '-');
    }
    void me::draw_title(const char *cstr)
    {
        mvwaddstr(impl, 0, (impl->_maxx - strlen(cstr)) / 2, cstr);
    }
}