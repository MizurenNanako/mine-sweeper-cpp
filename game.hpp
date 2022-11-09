#ifndef __game_hpp
#define __game_hpp

#include "util.hpp"

namespace cgt
{
    enum class game_state_t
    {
        main_menu,
        gaming,
        pause_menu,
        exiting,
    };

    class game_t
    {
    private:
        void *_impl;

    public:
        game_t();
        ~game_t();
        // @brief  Main Loop Entry
        void run();
    };
}

#endif // __game_hpp