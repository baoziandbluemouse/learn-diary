cmake_minimum_required(VERSION 3.31)
project(day36_lib)

set(CMAKE_CXX_STANDARD 20)

add_executable(day36_lib main.cpp)

#添加 Logger,Command 的包含目录
target_include_directories(day36_lib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Logger
        ${CMAKE_CURRENT_SOURCE_DIR}/Command)

#指定 Logger,Command 的库文件路径并进行链接
target_link_directories(day36_lib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Logger
        ${CMAKE_CURRENT_SOURCE_DIR}/Command)

#链接 Logger,Command 库
target_link_libraries(day36_lib PRIVATE Logger Command)