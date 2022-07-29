cmake_minimum_required(VERSION 3.9)

set(PATCH_VERSION "1" CACHE INTERNAL "patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(helloworld_cli VERSION ${PROJECT_VERSION})

configure_file(
    config.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/config.h
)

add_executable(
    helloworld_cli
    main.cpp
)

set_target_properties(
    helloworld_cli
    PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)

target_link_libraries(
    helloworld_cli
    PRIVATE
    serviceLib
)

target_include_directories(
    helloworld_cli
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Lib   
)

add_subdirectory(Lib)
add_subdirectory(Test)
add_subdirectory(
    ${CMAKE_CURRENT_SOURCE_DIR}/GTest
    "GoogleTest" EXCLUDE_FROM_ALL)

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}") 
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT billybones@admiral.com)

include(CPack)
enable_testing()
add_test(testLibrary ${CMAKE_CURRENT_BINARY_DIR}/Test/testServiceLib)

if(MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    target_compile_options(helloworld_cli
        PRIVATE
        /W4)
else() 
    target_compile_options(helloworld_cli
    PRIVATE
    -Wall -Wextra -pedantic -Werror
    )

endif()