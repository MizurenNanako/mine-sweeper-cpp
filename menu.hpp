#ifndef __menu_hpp
#define __menu_hpp

#include "util.hpp"

namespace cgt
{
    class menu_t
    {
    public:
        struct menu_item_t;

    private:
        void *_impl;

    public:
        menu_t();
        ~menu_t();
        menu_t &add_item(const menu_item_t &item);
        void sort();
        void render();
    };

    struct menu_t::menu_item_t
    {
        std::string name;
        func<void(void*)> callback;
    };
}

#endif // __menu_hpp