#include "input.hpp"
#include "printer.hpp"
#include <iostream>
#include <ncurses.h>

void __attribute__((constructor)) init();
void __attribute__((destructor)) destory();

int main()
{
    cgt::printer_t printer;
    cgt::input_t input;
    while (true)
    {
        cgt::input_event_t ev;
        ev = input.get_input();
        printer.puts(std::to_string(int(ev)));
        printer.show();
        if (ev == cgt::input_event_t::esc)
            break;
    }
    return 0;
}

void init() { initscr(); }
void destory() { endwin(); }