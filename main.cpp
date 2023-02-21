#include <iostream>

import cxx.math;
import cxx.utils.module2;


int main()
{
    std::cout << cxx::math::some_function() << std::endl;
    std::cout << cxx::math::v1 << std::endl;
    cxx::math::call_something_from_header();
    cxx::utils::S s;

    return 0;
}
