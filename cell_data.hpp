#ifndef __cell_data_hpp
#define __cell_data_hpp

#include "util.hpp"

namespace cgt
{
    namespace cell
    {
        typedef char cell_t;
        enum class data : cell_t
        {
            none = 0,
            num_1 = 1,
            num_2 = 2,
            num_3 = 3,
            num_4 = 4,
            num_5 = 5,
            num_6 = 6,
            num_7 = 7,
            num_8 = 8,
            bomb,
        };
        enum class mask : cell_t
        {
            none = 0,
            block = 1,
            flag = 2,
        };
    }
}

#endif // __cell_data_hpp