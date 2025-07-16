//
// Created by baozi on 2025/7/15.
//
#include "global.h"
#include <iostream>
const int global2 = 100; // 在源文件中定义一个全局常量

void show()
{
    std::cout << "在global.cpp中查询global和global2" << std::endl;
    // 输出全局常量的值
    std::cout << "Global2 constant value: " << global2 << std::endl;
    std::cout << "Global constant value: " << global << std::endl;
    // 输出两个常量的地址
    std::cout << "Address of global2: " << &global2 << std::endl;
    std::cout << "Address of global: " << &global << std::endl;
}
