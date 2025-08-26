//
// Created by baozi on 2025/8/1.
//

#include "interview.h"
#include <iostream>


void useVirtualTable()
{
    Baseclass b;
    b.f();
    //std::cout << "size of (b) is: " << sizeof(b) << std::endl;
    //int* p = (int*)&b;
    // int*强转，方便待会进行偏移
    // 因为所有指针都是8字节，所以可以进行int*强转
    //std::cout << "pointer address of virtual table is: " << p << std::endl;
    //std::cout << &b << std::endl;

    //首先，b的首地址存储的是一个指针，这个指针指向虚函数表的地址
    //然后，虚函数表存储了所有虚函数，这些虚函数都是以函数指针的形式存储
    //因此，p是一个三级指针，第一级是函数指针，第二级是指向虚函数表的指针，第三级是他本身
    //虚函数表指针是一个二级指针，可以理解为一个数组，存储的每个元素都是一个函数指针
    void** vtable = *(void***)(&b);
    std::cout << "vtable address is: " << vtable << std::endl;
    Func pf;
    pf = (Func)vtable[0];
    //相当于b.f()的调用
    //pf(&b); // 调用Baseclass的f函数，函数寻址法

    //对齐：类(结构体)对象每个成员分配内存的起始地址为其所占空间的整数倍。
    //补齐：类(结构体)对象所占用的总大小为其内部最大成员所占空间的整数倍。

    //Deriveclass的对象会继承Baseclass的虚函数表，并且如果有重写的函数，就会替换。
    //如果有新增的函数，就会在虚函数表中添加新的函数指针。
    //所以使用虚函数能够实现多态，就是因为base *p = new Derived();
    //此时 p指向的是Derived的虚函数表，而不是Baseclass的虚函数表
}
