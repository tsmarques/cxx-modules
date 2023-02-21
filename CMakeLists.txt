cmake_minimum_required(VERSION 3.24)
project(cxx_modules)

set(CMAKE_CXX_STANDARD 20)
set(PREBUILT_MODULE_PATH ${CMAKE_BINARY_DIR}/mod)

include(cmake/Modules.cmake)

add_module(cxx.math src/math.cppm)
add_executable(cxx_modules main.cpp src/math.cppm src/stuff.hpp)

include_directories(src)

add_dependencies(cxx_modules cxx.math.pcm)

target_compile_options(cxx_modules PUBLIC -fmodules)
target_compile_options(cxx_modules PUBLIC -fbuiltin-module-map)
target_compile_options(cxx_modules PUBLIC -fimplicit-module-maps)
target_compile_options(cxx_modules PUBLIC -fprebuilt-module-path=${PREBUILT_MODULE_PATH})
