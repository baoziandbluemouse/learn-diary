//
// Created by baozi on 2025/7/26.
//

#ifndef DRIVE_H
#define DRIVE_H

#include <iostream>

class Base
{
public:
    Base(int privateNum, int protectedNum) : privateNum(privateNum),
                                             protectedNum(protectedNum)
    {
        //std::cout << "Base" << std::endl;
    }

    ~Base()
    {
        //std::cout << "~Base" << std::endl;
    }

    void BaseFunc()
    {
        // std::cout << "BaseFunc" << std::endl;
        // std::cout << "PrivateNum: " << privateNum << std::endl;
        // std::cout << "ProtectedNum: " << protectedNum << std::endl;
    }

    //写上virtual关键字，表示这是一个虚函数
    //虚函数可以被继承类重写
    //当通过基类指针或引用调用该函数时，假如子类有重写该函数，那么就会调用子类的函数
    //如果子类没有重写该函数，那么就会调用基类的函数
    //虚函数的作用是实现多态
    virtual void display()
    {
        std::cout << "Base Virtual Func" << std::endl;
        std::cout << "PrivateNum: " << privateNum << std::endl;
        std::cout << "ProtectedNum: " << protectedNum << std::endl;
    }

    virtual void print() = 0; // 纯虚函数，必须在派生类中实现（类似java中的abstract抽象方法)

private:
    int privateNum;

protected:
    int protectedNum;
};

class Derive : public Base
{
public:
    Derive(): Base(1, 2)
    {
        //这两种列表调用构造函数用的是委托构造(c++11)
        //std::cout << "Derive" << std::endl;
    }

    Derive(int num1, int num2): Base(num1, num2)
    {
        // std::cout << "Derive" << std::endl;
    }

    ~Derive()
    {
        //std::cout << "Derive Destructor" << std::endl;
    }

    void DerivedFunc()
    {
        std::cout << "DriveFunc" << std::endl;
        //std::cout << "PrivateNum: " << privateNum << std::endl;
        //继承只能访问protected成员，不能访问private成员
        std::cout << "ProtectedNum: " << protectedNum << std::endl;
    }

    void display() override
    {
        std::cout << "Drive Virtual Func" << std::endl;
        //std::cout << "PrivateNum: " << privateNum << std::endl;
        std::cout << "ProtectedNum: " << protectedNum << std::endl;
    }

    //重写基类的display函数
    //重写需要返回类型，函数名一致
    //使用override关键字可以让编译器检查是否真的重写了基类
};

class Vehicle
{
public:
    virtual void startEngine() = 0;
};

class Car : public Vehicle
{
public:
    void startEngine() override { std::cout << "Car start" << std::endl; }
};

//访问控制
//公有继承
//基类的 public 成员在派生类中保持 public。
//基类的 protected 成员在派生类中保持 protected。
//基类的 private 成员在派生类中不可访问。
//保护继承
//基类的 public 成员在派生类中变为 protected。
//基类的 protected 成员在派生类中保持 protected。
//基类的 private 成员在派生类中不可访问。
//私有继承
//全部成员（public、protected、private）在派生类中都变为 private。

//构造函数的调用顺序
// 基类的 默认构造函数 首先被调用，除非派生类在初始化列表中显式调用其他基类构造函数。
// 派生类的成员按照声明顺序被构造。
// 派生类的构造函数体被执行。

//切片问题
//C++ 容器（如 std::vector、std::list 等） 通常存储对象的副本，而非指向对象的指针。
//因此，当与继承结合使用时，可能导致 切片（Object Slicing） 问题.
//即仅存储基类部分，丢失派生类特有的信息。
//为了实现多态性，推荐使用指针或智能指针存储对象。


#endif //DRIVE_H
