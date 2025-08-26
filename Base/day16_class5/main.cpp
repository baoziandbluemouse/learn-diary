#include <iostream>

//友元：可以访问类的私有和保护成员的非成员函数或另一个类。
//适用场景：一些类的私有成员不希望提供public的接口，但希望有一些类能够通过接口调取。
//这时会用友元，就可以实现这个效果
//友元函数：单个函数可以被声明为友元。
//友元类：整个类可以被声明为友元。
class AreaCalculator;

class Rectangle
{
public:
    Rectangle(double width, double height) : width_(width), height_(height)
    {
    }

private:
    double width_;
    double height_;

    // 声明友元类
    friend class AreaCalculator;
};

class AreaCalculator
{
public:
    double calculateArea(const Rectangle& rect)
    {
        return rect.width_ * rect.height_;
    }
};

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
