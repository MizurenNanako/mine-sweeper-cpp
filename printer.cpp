#include "printer.hpp"
#include "ncurses.hpp"
#include <atomic>

struct printer_impl
{
    cgt::ncurses_t ncurse;
    void render_menu();
    void render_game();
    void render_info_panel();
    void render_info_line();
};

static std::atomic<size_t> _ref_cnt{0};

namespace cgt
{
#define impl ((struct printer_impl *)(_impl))
    printer_t::printer_t()
    {
        if (!_ref_cnt.load())
            _impl = new printer_impl;
        ++_ref_cnt;
    }

    printer_t::~printer_t()
    {
        --_ref_cnt;
        if (!_ref_cnt.load())
            delete impl;
    }
    void printer_t::render()
    {
    }
    void printer_t::show()
    {
        ncurses_t::refresh();
    }
    void printer_t::clear()
    {
        clear();
    }
}