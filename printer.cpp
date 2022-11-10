#include "printer.hpp"
#include "ncurses.hpp"

struct printer_impl
{
    cgt::ncurses_t ncurse;
};

namespace cgt
{
#define impl ((struct printer_impl *)(_impl))
    printer_t::printer_t()
    {
        _impl = new printer_impl;
    }

    printer_t::~printer_t()
    {
        delete impl;
    }
    void printer_t::render()
    {
    }
    void printer_t::show()
    {
        refresh();
    }
    void printer_t::clear()
    {
        clear();
    }
    void printer_t::puts(std::string str)
    {
        printw(str.c_str());
    }
}