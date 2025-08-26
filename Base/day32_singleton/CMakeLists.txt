cmake_minimum_required(VERSION 3.31)
project(day32_singleton)

set(CMAKE_CXX_STANDARD 20)

add_executable(day32_singleton main.cpp
        singleton.cpp
        singleton.h)
