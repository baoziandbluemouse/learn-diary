cmake_minimum_required(VERSION 3.31)
project(day30_log)

set(CMAKE_CXX_STANDARD 20)

add_executable(day30_log main.cpp
        logger.cpp
        logger.h)
