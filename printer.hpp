#ifndef __printer_hpp
#define __printer_hpp

#include "util.hpp"

namespace cgt
{
    class printer_t
    {
    private:
        void *_impl;

    public:
        printer_t();
        ~printer_t();
        void render();
        static void show();
        static void clear();
    };
}

#endif // __printer_hpp