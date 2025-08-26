#include <iostream>
#include <vector>
#include "Base.h"
#include <memory>

int main()
{
    // std::vector<Base> vec;
    // Derived d;
    // vec.push_back(d); // 切片发生，派生类特有部分被丢弃
    // vec[0].show(); // 输出: Base show
    std::vector<std::unique_ptr<Base>> vec;
    vec.emplace_back(std::make_unique<Derived>());

    vec[0]->show(); // 输出: Derived show
    return 0;
}
