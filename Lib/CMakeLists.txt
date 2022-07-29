cmake_minimum_required(VERSION 3.9)

project(GeneralLib, 
    VERSION 0.0.1
    DESCRIPTION "Library for exercise01"
)

add_library(serviceLib STATIC lib.cpp lib.h)
set_target_properties(
    serviceLib
    PROPERTIES
    CXX_STANDARD    11
    CXX_STANDARD_REQUIRED ON
    )

target_include_directories(
    serviceLib
    PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/..
)

if(MSVC)
    target_compile_options(serviceLib
        PRIVATE
        /W4)
else() 
    target_compile_options(serviceLib
    PRIVATE
    -Wall -Wextra -pedantic -Werror
    )

endif()
