#ifndef __ncurses_hpp
#define __ncurses_hpp

#include "util.hpp"

namespace cgt
{
    class ncurses_t
    {
    public:
        class window_t;

    public:
        ncurses_t();
        ~ncurses_t();
        static void clear();
        static void refresh();
        static void draw_str(const char *cstr, pos_t pos);
        static void draw_ch(const char ch, pos_t pos);
        static void draw_hline(const char ch, pos_t pos, size_t len);
        static void draw_vline(const char ch, pos_t pos, size_t len);
        static void draw_box(const char ch, pos_t LT, pos_t RD);
        static int getkey();
    };

    class ncurses_t::window_t
    {
    private:
        void *_impl;

    public:
        window_t();
        ~window_t();
    };
}

#endif // __game_hpp