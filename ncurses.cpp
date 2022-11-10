#include "ncurses.hpp"
#include <ncurses.h>
#include <atomic>
#include <locale>

static std::atomic<size_t> _ref_cnt{0};

namespace cgt
{
    ncurses_t::ncurses_t()
    {
        if (!_ref_cnt.load())
        {
            // do some init
            std::setlocale(LC_ALL, "en_US");
            initscr();
            noecho();
            raw();
            intrflush(stdscr, FALSE);
            keypad(stdscr, TRUE);
            set_escdelay(10);
            clear();
            refresh();
        }
        ++_ref_cnt;
    }

    ncurses_t::~ncurses_t()
    {
        --_ref_cnt;
        if (!_ref_cnt.load())
        {
            // do some cleaning
            endwin();
        }
    }

    void ncurses_t::clear()
    {
        ::clear();
    }
    void ncurses_t::refresh()
    {
        ::refresh();
    }
    void ncurses_t::draw_str(const char *cstr, pos_t pos)
    {
        mvaddstr(pos.second, pos.first, cstr);
    }
    void draw_ch(const char ch, pos_t pos)
    {
        mvaddch(pos.second, pos.first, ch);
    }
    void ncurses_t::draw_hline(const char ch, pos_t pos, size_t len)
    {
        mvhline(pos.second, pos.first, ch, len);
    }
    void ncurses_t::draw_vline(const char ch, pos_t pos, size_t len)
    {
        mvvline(pos.second, pos.first, ch, len);
    }
    void ncurses_t::draw_box(const char ch, pos_t LT, pos_t RD)
    {
        pos_t B = RD - LT;
        mvhline(LT.second, LT.first, ch, B.first);     // top
        mvhline(RD.second, LT.first, ch, B.first + 1); // down
        mvvline(LT.second, LT.first, ch, B.second);    // left
        mvvline(LT.second, RD.first, ch, B.second);    // right
    }
    int ncurses_t::getkey()
    {
        return ::getch();
    }
}