#include <iostream>
#include "MyString.h"

int main()
{
    MyString str1("Hello, World!");
    MyString str2 = str1; // 拷贝构造
    MyString str3;

    str3 = str1; // 赋值运算符重载

    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;
    std::cout << "str3: " << str3 << std::endl;

    if (str1 == str2) std::cout << "str1 and str2 are equal." << std::endl;
    else std::cout << "str1 and str2 are not equal." << std::endl;
    return 0;
}
