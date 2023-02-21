module;

#include "stuff.hpp"

export module cxx.math;

export namespace cxx::math
{
    constexpr double v1 = 0.23;

    double some_function()
    {
        return 12.02;
    }

    void
    call_something_from_header()
    {
        stuff::do_something_from_header();
    }
}