#include <iostream>
//#include <stuff.hpp>

import cxx.math;


int main()
{
    std::cout << "Hello, World!" << std::endl;

    std::cout << cxx::math::some_function() << std::endl;
    std::cout << cxx::math::v1 << std::endl;

    cxx::math::call_something_from_header();

    return 0;
}
