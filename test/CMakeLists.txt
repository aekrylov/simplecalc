cmake_minimum_required(VERSION 2.6)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable( simplecalc_test testcalc.cpp)
# Link test executable against gtest & gtest_main
target_link_libraries(simplecalc_test gtest gtest_main)

target_link_libraries(simplecalc_test libsimplecalc)

# Gtest pthread issues workaround
find_package (Threads)
target_link_libraries(simplecalc_test ${CMAKE_THREAD_LIBS_INIT})

add_test(simplecalc_test simplecalc_test)
