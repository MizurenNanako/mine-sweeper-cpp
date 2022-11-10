#include "game.hpp"
#include "printer.hpp"
#include "board.hpp"
#include "input.hpp"

struct game_impl
{
    cgt::game_state_t state;
    cgt::board_t data_board;
    cgt::board_t mask_board;
    cgt::printer_t printer;
    cgt::input_t input;
    inline void run_loop()
    {
        while (true)
        {
            cgt::input_event_t ev;
            ev = input.get_input();
            printer.show();
            if (ev == cgt::input_event_t::esc)
                break;
        }
    }
};

namespace cgt
{
#define impl ((struct game_impl *)(_impl))
    game_t::game_t()
    {
        _impl = new game_impl;
    }

    game_t::~game_t()
    {
        delete impl;
    }

    void game_t::run()
    {
        impl->run_loop();
    }
}