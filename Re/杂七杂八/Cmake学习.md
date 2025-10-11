---
date: 2025-10-11
tags:
  - project
---
# 学习Cmake的三个部分

- Cmake变量
- Cmake命令
- Cmake在项目中的接口权限管理

# 常见Cmake变量

- `PROJECT_NAME` ：项目名称
- `PROJECT_BINARY_DIR` ：项目的二进制文件目录，即编译后的可执行文件和库文件的输出目录
- `PROJECT_SOURCE_DIR` ：项目的源文件目录，即包含CMakeLists.txt文件的目录
- `CMAKE_BINARY_DIR` ：当前CMake运行的二进制文件目录，通常和PROJECT_BINARY_DIR是同一个目录
- `CMAKE_SOURCE_DIR` ：当前CMake运行的源文件目录，通常和PROJECT_SOURCE_DIR是同一个目录
- `CMAKE_C_STANDARD` ：指定C语言的标准版本
- `CMAKE_CXX_STANDARD` ：指定C++语言的标准版本
- `CMAKE_CXX_FLAGS` ：指定编译C++代码时使用的编译选项
- `CMAKE_C_FLAGS` ：指定编译C代码时使用的编译选项
- `CMAKE_EXE_LINKER_FLAGS` ：指定链接可执行文件时使用的链接选项
- `CMAKE_SYSTEM_NAME` ：指定当前操作系统名称（如Windows、Linux等）
- `CMAKE_SYSTEM_PROCESSOR` ：指定当前处理器的类型（如x86、x86_64等）
- `CMAKE_CXX_COMPILER_ID` ：指定了当前使用的C++编译器，同理可得C的编译器对应的名字。

一些简单的作用

1. 打印项目信息
```Cmake
set(A ON)  
if(A)  
    message(STATUS: \t${PROJECT_NAME})  
    message(STATUS:  \t${PROJECT_BINARY_DIR})  
    message(STATUS:  \t${PROJECT_SOURCE_DIR})  
else()  
  
endif()
```

2. 通过变量检测环境执行不同的cmake代码

```Cmake
#判断当前的操作系统
if (CMAKE_SYSTEM_NAME MATCHES "Linux")
    target_link_libraries(my-logger PUBLIC fmt-header-only pthread)
    message(STATUS "Now is Linux")
elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
    target_link_libraries(my-logger PUBLIC fmt-header-only ws2_32)
    message(STATUS "Now is windows")
endif ()
#判断当前使用的编译器
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  # Do something for GCC
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
  # Do something for Intel C++
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Microsoft")
  # Do something for Microsoft Visual C++
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  # Do something for Clang
endif()

#判断当前的系统架构
if (CMAKE_SYSTEM_PROCESSOR MATCHES "i.86|x86|x86_64|AMD64")
  # Do something for x86 architecture
elseif (CMAKE_SYSTEM_PROCESSOR MATCHES "^(arm|aarch64)")
  # Do something for ARM architecture
elseif (CMAKE_SYSTEM_PROCESSOR MATCHES "^(mips|mipsel|mips64)")
  # Do something for MIPS architecture
elseif (CMAKE_SYSTEM_PROCESSOR MATCHES "^(powerpc|ppc64)")
  # Do something for PowerPC architecture
endif()

```

3. 通过调整链接时的flag防止动态链接，因为如果你是使用Windows平台下的编译工具链，CLion有些时候最终链接并不是采用静态链接，导致你最终生成的可执行程序没法直接执行，这个时候你就需要使用下面的命令来强制静态链接了：

```
set(CMAKE_EXE_LINKER_FLAGS "-static")
```


# 常见Cmake命令

1. project 用于定义项目名称、版本号和语言。
2. add_executable 用于添加可执行文件。第一个参数很重要，被称为**target**，可以作为target_xxx命令的接收对象。
3. add_library 用于添加库文件，可以创建静态库或动态库。第一个参数很重要，被称为target，可以作为target_xxx命令的接收对象。简单使用如下
```CMake
add_library(test_lib a.cc b.cc) #默认生成静态库
add_library(test_lib SHARED a.cc b.cc) #生成了动态库
```

4. link_directories: 添加的是库的搜索路径，告诉**cmake要找库就去这里找**，后续只要把库的名字添加就好了
5. include_directories: 用于指定头文件搜索路径，优点是简单直接，缺点是无法进行权限控制，一旦被执行后，后续的所有代码都能搜索到对应的文件路径。和上面的link差不多
6. add_subdirectory: 用于添加子项目目录，如果**有该条语句，就先会跑去执行子项目的cmake代码，这样会导致一些需要执行后立马生效的语句作用不到，比如include_directories和link_directories**,如果执行在这条语句后面，则他们添加的目录在子项目中无法生效。有些命令如**target_include_directories和target_link_directories是根据目标target是否被链接使用来生效的，所以这些命令的作用范围与执行顺序无关，且恰好同一个cmake项目中产生的库文件是可以直接通过名称链接的，无论链接对象是在子目录还是父目录**
7. add_definitions: 用于*添加宏定义*，注意该命令没有执行顺序的问题，只要改项目中用了该命令定义宏，那么所有的源代码都会被定义这个宏 `add_definitions(-DFOO -DBAR ...)` 。
8. message: *打印出信息用于debug*。
9. aux_source_directory: 这个指令简单实用，第一个参数*传递一个文件目录*，它会扫描这里面*所有的源文件放到第二个参数定义的变量名*中。注意第一个参数只能是文件夹。所以当我们项目庞大时，添加可执行文件就变得很困难（写好多个cpp）这时使用这个命令就能一键获取
```cmake
aux_source_directory(${PROJECT_SOURCE_DIR} SRC)
```

10. file: 可以说是上面那个命令的增强版本,*它具备几乎文件系统的所有功能*,什么读写文件啊，什么从网上下载文件，本地上传文件之类的它都有，计算文件的相对路径，路径转化等等。但*我们平时用到的最多的命令还是用来获取文件到变量里*。比如file(GLOB FILES "文件路径表示1" "文件路径表示2" ...) GLOB会产生一个由所有匹配globbing表达式的文件组成的列表，并将其保存到第二个参数定义的变量中。Globbing 表达式与正则表达式类似，但更简单，比如如果要实现前一个命令的功能可以这么写：
```Cmake
file(GLOB SRC "${PROJECT_SOURCE_DIR}/*.cc")
```

如果*GLOB 换成GLOB_RECURSE*，那么上述命令将递归的搜寻其子目录的所有符合条件的文件，而不仅仅是一个层级。
11. execute_process: 用于执行外部的命令，如下的示例代码是执行git clone命令，执行命令的工作目录在 `${CMAKE_BINARY_DIR}/deps/`
```cmake
execute_process(COMMAND git clone https://github.com/<username>/<repository>.git
                WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/deps/<repository>)
```

12. target_link_libraries: 用于将**可执行文件或库文件链接到库文件或可执行文件**。身为target_xxx的一员，很明显第二个参数也可以进行权限控制。要使用的话一定要先添加库的搜索路径，这里只写出**库名字**
