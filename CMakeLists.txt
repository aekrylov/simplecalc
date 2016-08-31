cmake_minimum_required(VERSION 2.6)
project(simplecalc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


set(SOURCE_FILES
        src/Calculator.cpp include/Calculator.h)

add_executable(simplecalc src/main.cpp)
add_library(libsimplecalc ${SOURCE_FILES})
target_link_libraries(simplecalc libsimplecalc)

enable_testing()
add_subdirectory(test)
