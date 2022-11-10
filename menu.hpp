#ifndef __menu_hpp
#define __menu_hpp

#include "util.hpp"

namespace cgt
{
    class menu_t
    {
    private:
        void *_impl;

    public:
        menu_t();
        ~menu_t();
    };
}

#endif // __menu_hpp