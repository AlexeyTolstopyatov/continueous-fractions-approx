cmake_minimum_required(VERSION 3.28)
project(chview)

set(CMAKE_CXX_STANDARD 20)

add_executable(chview main.cpp
        exps/Chained.cpp
        exps/Chained.hpp
        exps/Exponential.cpp
        exps/Exponential.hpp)
