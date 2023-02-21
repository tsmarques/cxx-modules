cmake_minimum_required(VERSION 3.24)
project(cxx_modules)

set(CMAKE_CXX_STANDARD 20)

set(PREBUILT_MODULE_PATH ${CMAKE_BINARY_DIR}/mod)
file(MAKE_DIRECTORY ${PREBUILT_MODULE_PATH})

include(cmake/Modules.cmake)

include_directories(src)

# find modules
file(GLOB_RECURSE CXX_MODULES_SRCS ${_path} "*.cppm")

add_executable(cxx_modules main.cpp ${CXX_MODULES_SRCS} src/stuff.hpp)
target_compile_options(cxx_modules PUBLIC -fmodules)
target_compile_options(cxx_modules PUBLIC -fbuiltin-module-map)
target_compile_options(cxx_modules PUBLIC -fimplicit-module-maps)
target_compile_options(cxx_modules PUBLIC -fprebuilt-module-path=${PREBUILT_MODULE_PATH})

# prepare modules and add dependency
foreach(_module ${CXX_MODULES_SRCS})
    add_module(cxx_modules ${PROJECT_SOURCE_DIR}/src ${_module})
endforeach()

