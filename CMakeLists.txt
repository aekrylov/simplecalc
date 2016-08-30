cmake_minimum_required(VERSION 2.6)
project(simplecalc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        src/calc.cpp include/calc.h)

add_executable(simplecalc ${SOURCE_FILES})

add_subdirectory(test)
