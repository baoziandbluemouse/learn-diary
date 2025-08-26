cmake_minimum_required(VERSION 3.31)
project(day22_work)

set(CMAKE_CXX_STANDARD 20)

add_executable(day22_work main.cpp
        ResourceManager.cpp
        ResourceManager.h
        GraphNode.cpp
        GraphNode.h)
