#ifndef __input_hpp
#define __input_hpp

#include "util.hpp"

namespace cgt
{
    enum class input_event_t : char
    {
        esc,
        up,
        down,
        left,
        right,
        select,
        mark,
    };
    class input_t
    {
    private:
        void *impl;

    public:
        input_t();
        ~input_t();
        input_event_t get_input();
    };
}

#endif // __game_hpp