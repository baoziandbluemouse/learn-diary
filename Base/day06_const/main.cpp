#include <iostream>
#include "global.h"
int global_int = 100;
int global_int2 = 200; // 定义一个全局变量
int main()
{
    /*
     *用名词顶层const（top-level const）表示指针本身是个常量
     *而用名词底层const（low-level const）表示指针所指的对象是一个常量。
     *这是针对指针而言的。更广泛地说
     *顶层const可以表示任意的对象是常量，这一点对任何数据类型都适用，如算术类型、类、指针等。
     *底层const则与指针和引用等复合类型的基本类型部分有关。
     */
    // const 修饰的变量在编译时会被视为只读，尝试修改其值会导致编译错误。
    // 此外，编译器可能会对 const 变量进行优化，如将其存储在只读内存区域。
    // 另外，默认状态下，const对象仅在文件内有效
    // 也就是说，多文件的情况下，假如有两个同名的const变量，它们不会冲突。
    // 例如，在头文件中定义一个const变量
    system("chcp 65001"); // 调用控制台UTF-8编码
    show();
    std::cout << "\n----------------------\n";
    std::cout << "在main.cpp中查询global和global2" << std::endl;
    std::cout << "Global2 constant value: " << global2 << std::endl;
    std::cout << "Global constant value: " << global << std::endl;
    std::cout << "Address of global2: " << &global2 << std::endl;
    std::cout << "Address of global: " << &global << std::endl;
    // 常量表达式（const expression）是指值不会改变并且在编译过程就能得到计算结果的表达式。
    {
        // 一个constexpr指针的初始值必须是nullptr或者0，或者是存储于某个固定地址中的对象。
        // 固定地址的对象可以是全局变量、静态变量或数组等。
        // 而且constexpr指针还有* const指针的特性，即指针指向的地址不能被修改。
        int i6 = 10;
        constexpr int* p6 = &global_int;
    }
    return 0;
}
