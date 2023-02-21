module;

#include <iostream>

export module cxx.utils.module2;

namespace cxx::utils
{
    static void
    function_not_exported()
    {
        std::cout << "cxx::utils::function_not_exported\n";
    }


    export struct S
    {
        S()
        {
            std::cout << "cxx::utils::S\n";
            function_not_exported();
        }
    };
}