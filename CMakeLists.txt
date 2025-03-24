cmake_minimum_required(VERSION 3.14)
project(PR2_3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(../PR2_3/lib/googletest)

include_directories(/opt/homebrew/opt/ncurses/include)
link_directories(/opt/homebrew/opt/ncurses/lib)

add_executable(PR2_3
        main.cpp
        classes/Fraction.cpp
)

target_link_libraries(PR2_3)

add_executable(PR2_3_tests
        classes/Fraction.cpp
        tests/tests.cpp
)

target_link_libraries(PR2_3_tests gtest gtest_main)

enable_testing()
include(GoogleTest)
gtest_discover_tests(PR2_3_tests)
