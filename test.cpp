#include "game.hpp"
#include "ncurses.hpp"

int main()
{
    // cgt::game_t game;
    // game.run();
    cgt::ncurses_t n;
    n.draw_box('a', cgt::pos_t{1, 1}, cgt::pos_t{15, 6});
    n.draw_hline('-', cgt::pos_t{0, 0}, 10);
    n.refresh();
    n.getkey();
    return 0;
}
