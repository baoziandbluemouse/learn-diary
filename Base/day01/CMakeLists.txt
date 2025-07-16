set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -save-temps=obj")
set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -save-temps=obj")


cmake_minimum_required(VERSION 3.31)
project(day01)

set(CMAKE_CXX_STANDARD 20)

add_executable(day01 main.cpp)
