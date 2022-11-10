#include "game.hpp"
#include "ncurses.hpp"

int main()
{
    using cgt::pos_t;
    // cgt::game_t game;
    // game.run();
    cgt::ncurses_t n;
    cgt::ncurses_t::window_t w;
    w.draw_box('a', pos_t{} + 2, w.size() - 2);
    w.draw_border();
    w.draw_title("adddd");
    n.draw_hline('-', pos_t{0, 0}, 10);
    w.refresh();
    n.refresh();
    n.getkey();
    return 0;
}
