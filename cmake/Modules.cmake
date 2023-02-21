# declare a module and add it as depedency to a target
function(add_module _target _base_path _module_path)
    ## relative path
    file(RELATIVE_PATH _module_rel_path ${_base_path} ${_module})
    get_filename_component(_module_rel_path ${_module_rel_path} DIRECTORY)

    ## module filename without extension
    get_filename_component(_module_name ${_module} NAME_WE)
    # not empty / root directory
    if (NOT ${_module_rel_path} STREQUAL "")
        set(_module_name "${_module_rel_path}/${_module_name}")
        ## module final name
        string(REPLACE "/" "." _module_name ${_module_name})
    endif()

    set(_module_name cxx.${_module_name})
    set(_module_pcm ${_module_name}.pcm)

    add_custom_target(${_module_pcm}
            COMMAND
            ${CMAKE_CXX_COMPILER}
            -std=gnu++20
            -x c++
            -fmodules
            -Isrc
            -c
            ${_module_path}
            -Xclang -emit-module-interface
            -o ${PREBUILT_MODULE_PATH}/${_module_pcm}
            )

    message(STATUS "declaring module ${_module_name} from ${_module_path}")

    add_dependencies(cxx_modules ${_target} ${_module_pcm})
endfunction()