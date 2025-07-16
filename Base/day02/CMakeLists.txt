
# 设置CMake的最小版本要求
cmake_minimum_required(VERSION 3.31)
# 设置项目名称和版本
project(day02 VERSION 1.0)
# 设置C++标准
set(CMAKE_CXX_STANDARD 20)
# 添加源文件
set(SOURCE_FILES main.cpp
        example.cpp)
# 添加可执行文件
add_executable(day02 ${SOURCE_FILES})
