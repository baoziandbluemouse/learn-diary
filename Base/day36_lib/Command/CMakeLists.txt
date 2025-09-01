cmake_minimum_required(VERSION 3.31)
project(Command)

set(CMAKE_CXX_STANDARD 20)

add_library(Command SHARED Command.cpp
        TaskManager.cpp
        TaskManager.h
        Task.cpp
        Task.h
        CommandImpl.cpp
        CommandImpl.h)

#定义导出宏
target_compile_definitions(Command PRIVATE COMMAND_BUILDING_DLL)

# 添加 Logger 的包含目录
target_include_directories(Command PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}   # 包含当前目录的头文件（如CommandExport.h）
        ../Logger                     # 包含Logger的头文件, ..代表上一级目录
)

# 指定Logger的库文件路径并链接
target_link_directories(Command PRIVATE ../Logger)  # 假设Logger.lib和Logger.dll在此目录
target_link_libraries(Command PRIVATE Logger)      # 链接Logger库