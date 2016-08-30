cmake_minimum_required(VERSION 2.6)
project(calculator_test)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(SOURCE_FILES
        ../src/calc.cpp ../include/calc.h)


add_executable( calculator_test main.cpp )
# Link test executable against gtest & gtest_main
target_link_libraries(calculator_test gtest gtest_main)
add_test( calculator_test calculator_test )
