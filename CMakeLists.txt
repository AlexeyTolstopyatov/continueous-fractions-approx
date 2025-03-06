cmake_minimum_required(VERSION 3.28)
project(chview)

set(CMAKE_CXX_STANDARD 20)

add_executable(chview main.cpp
        chains/Chained.cpp
        chains/Chained.hpp
        exponents/Exponential.cpp
        exponents/Exponential.hpp)
