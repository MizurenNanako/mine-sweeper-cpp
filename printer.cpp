#include "printer.hpp"
#include <ncurses.h>
#include <locale>

struct printer_impl
{
    printer_impl()
    {
        noecho();
        clear();
        refresh();
    }
    ~printer_impl()
    {
    }
};

typedef struct printer_impl *m;

namespace cgt
{
    printer_t::printer_t(/* args */)
    {
        impl = new printer_impl;
    }

    printer_t::~printer_t()
    {
        delete m(impl);
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