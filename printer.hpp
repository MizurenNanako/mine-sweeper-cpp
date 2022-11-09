#ifndef __printer_hpp
#define __printer_hpp

#include "util.hpp"

namespace cgt
{
    class printer_t
    {
    private:
        void *impl;

    public:
        printer_t(/* args */);
        ~printer_t();
        void render();
        void show();
        void clear();
        void puts(std::string str);
    };
}

#endif // __printer_hpp