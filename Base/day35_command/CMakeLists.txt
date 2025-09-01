cmake_minimum_required(VERSION 3.31)
project(day35_command)

set(CMAKE_CXX_STANDARD 20)

add_executable(day35_command main.cpp
        Logger.cpp
        Logger.h
        Task.cpp
        Task.h
        TaskManager.cpp
        TaskManager.h
        Command.cpp
        Command.h)
