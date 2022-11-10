#include "ncurses.hpp"
#include <ncurses.h>
#include <atomic>
#include <locale>

std::atomic<size_t> _ref_cnt{0};

namespace cgt
{
    ncurses_t::ncurses_t()
    {
        if (!_ref_cnt.load())
        {
            // do some init
            std::setlocale(LC_ALL,"en_US");
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
}