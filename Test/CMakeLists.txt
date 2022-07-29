cmake_minimum_required(VERSION 3.9)
project(testLibrary VERSION 0.0.1)

add_executable(testServiceLib test.cpp)
set_target_properties(
    testServiceLib
    PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)

target_link_libraries(
    testServiceLib
    PRIVATE
    serviceLib
    gtest
    gtest_main
    )

target_include_directories(
    testServiceLib
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../Lib
)

if(MSVC)
    target_compile_options(testServiceLib
        PRIVATE
        /W4)
else() 
    target_compile_options(testServiceLib
    PRIVATE
    -Wall -Wextra -pedantic -Werror
    )

endif()