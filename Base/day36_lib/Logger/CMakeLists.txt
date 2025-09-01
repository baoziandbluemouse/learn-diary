cmake_minimum_required(VERSION 3.31)
project(Logger)

set(CMAKE_CXX_STANDARD 20)

add_library(Logger SHARED Logger.cpp)
#SHARED代表动态库，STATIC代表静态库

target_compile_definitions(Logger PRIVATE LOGGER_BUILDING_DLL)
#定义宏LOGGER_BUILDING_DLL
#当编译时，到Cmake文件就会定义这个宏，然后.h文件就会知道现在是在导出了
#接着进行编译，就会生成动态库了，把.dll文件移动到一个位置，项目想要使用就再用Cmake从这个位置导入就好了
