cmake_minimum_required(VERSION 3.31)

set(VCPKG_TARGET_TRIPLET "x64-mingw-dynamic" CACHE STRING "")
set(VCPKG_TARGET_TRIPLET "x64-mingw-static" CACHE STRING "")

project(helloworld)


set(CMAKE_CXX_STANDARD 20)

add_executable(helloworld main.cpp)
