#ifndef CXX_MODULES_STUFF_HPP
#define CXX_MODULES_STUFF_HPP

#include <iostream>

namespace cxx::stuff
{
    void
    do_something_from_header()
    {
        std::cout << "cxx::stuff::do_something_from_header\n";
    }
}

#endif//CXX_MODULES_STUFF_HPP
