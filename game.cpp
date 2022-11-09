#include "game.hpp"
#include "printer.hpp"
#include "board.hpp"

struct game_impl
{
    cgt::game_state_t state;
    cgt::board_t data_board;
    cgt::board_t mask_board;
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
    }
}