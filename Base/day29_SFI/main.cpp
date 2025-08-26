#include <iostream>
#include "sfinae.h"
//SFINAE
//SFINAE 是 “Substitution Failure Is Not An Error”（替换失败不是错误）的缩写，是C++模板编程中的一个重要概念。
//它允许编译器在模板实例化过程中，如果在替换模板参数时失败（即不满足某些条件），不会将其视为编译错误，而是继续寻找其他可能的模板或重载。
//这一机制为条件编译、类型特性检测、函数重载等提供了强大的支持。
//SFINAE是一个古早的C++特性，在后续c++标准中有所简化，如果要考虑到兼容早版本，还是要使用SFINAE。


//应用原理：
//在模板实例化过程中，编译器会尝试将模板参数替换为具体类型。
//如果在替换过程中出现不合法的表达式或类型，编译器不会报错，而是将该模板视为不可行的，继续尝试其他模板或重载。
//这一特性允许开发者根据类型特性选择不同的模板实现。

//所以假如使用SFINAE，报错只有在所有模板都不匹配时才会发生。

//应用场景:
//函数重载选择：根据参数类型的不同选择不同的函数实现。
//类型特性检测：检查一个类型是否满足某些条件（如是否为整数、是否有某个成员函数等）。
//条件编译：根据类型特性或其他条件选择不同的模板实现。


int main()
{
    int x = 10;
    TypePrinter<WithValueType>::print();
    // 输出: T has a member type 'value_type'.
    TypePrinter<WithoutValueType>::print();
    // 输出: hello world! T does not have a member type 'value_type'.
    TypePrinter<WithVoidValueType>::print();
    // 输出: hello world! T does not have a member type 'value_type'.
    return 0;
}
