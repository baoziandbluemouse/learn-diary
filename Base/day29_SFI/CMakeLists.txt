cmake_minimum_required(VERSION 3.31)
project(day29_SFI)

set(CMAKE_CXX_STANDARD 20)

add_executable(day29_SFI main.cpp
        sfinae.cpp
        sfinae.h)
