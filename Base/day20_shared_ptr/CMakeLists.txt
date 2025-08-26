cmake_minimum_required(VERSION 3.31)
project(day20_shared_ptr)

set(CMAKE_CXX_STANDARD 20)

add_executable(day20_shared_ptr main.cpp
        SimpleSharedPtr.cpp
        SimpleSharedPtr.h)
