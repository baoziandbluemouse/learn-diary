#include <iostream>
#include "logger.h"
#include <string>

//模板元编程（Template Metaprogramming）
//是一种在编译期通过模板机制进行代码生成和计算的编程技术。
//它利用编译器的模板实例化机制，在编译期间执行代码逻辑，以提高程序的性能和灵活性。
//模板元编程可以使用特化模板，也可以使用递归模板
//模板元编程可以计算些常量，也可以进行类型计算，比如看两个类型能不能相加


int main()
{
    // int a = 10;
    // Logger<int>::log(a); // Logging value: 10
    // int* p = &a;
    // Logger<int*>::log(p); // Logging pointer value: 10
    // std::string s = "Hello, World!";
    // Logger<std::string>::log(s);
    // logAll(a, p, s, nullptr);
    //std::cout << Factorial<5>::value << std::endl;
    //std::cout << Factorial<0>::value << std::endl;
    // 使用
    //static_assert(is_addable<int>::value, "int should be addable");
    //static_assert(!is_addable<void*>::value, "void* should not be addable");


    //std::cout << Fibonacci<5>::value << std::endl;
    //std::cout << Fibonacci<10>::value << std::endl;

    //std::cout << Sum<1, 2, 3, 4, 5>::value << std::endl;

    using List = TypeList<int, double, char>;
    using third_type = TypeAt<List, 2>::type; // 获取第三个类型
    std::cout << "TypeAt<List, 2> = " << typeid(third_type).name() << std::endl;
    return 0;
}
