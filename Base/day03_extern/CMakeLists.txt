cmake_minimum_required(VERSION 3.31)
project(day03_extern)

set(CMAKE_CXX_STANDARD 20)

add_executable(day03_extern main.cpp
        global.h
        global.cpp)
