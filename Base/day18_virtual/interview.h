//
// Created by baozi on 2025/8/1.
//

#ifndef INTERVIEW_H
#define INTERVIEW_H
#include <iostream>

//虚函数表原理
//一个类对象其内存分布的基本结构为虚函数表地址+非静态成员变量。
//类的成员函数不占用类对象的空间，他们分布在一片属于类的共有区域。
//虚函数表的地址存储在类对象的起始位置。
//所以我们可以利用这个原理，通过寻址的方式访问虚函数表里的函数


class Baseclass
{
public:
    Baseclass(): a(1024)
    {
    }

    virtual ~Baseclass() = default;
    virtual void f() { std::cout << "Base f" << std::endl; }
    virtual void g() { std::cout << "Base g" << std::endl; }
    virtual void h() { std::cout << "Base h" << std::endl; }

    //内存分配
    //0 1 2 3   4 5 6 7 虚函数表地址存储占8个字节（64位，在32位中是4个字节）
    //8 9 10 11   12 13 14 15 a这个非静态成员变量，虽然他是4字节
    //但是由于内存补齐的原因，编译器会在a后面补齐4个字节，所以总共占用16个字节
    int a;
};

class Derivedclass : public Baseclass
{
public:
    //override
    virtual void f() override { std::cout << "Derived f" << std::endl; }
    virtual void g2() { std::cout << "Derived g2" << std::endl; }
    virtual void h3() { std::cout << "Derived h3" << std::endl; }
};

typedef void (*Func)(void*);
extern void useVirtualTable();

// 基类 Device
class Device
{
public:
    std::string brand;

    Device(const std::string& brand_) : brand(brand_)
    {
    }

    void showBrand() const { std::cout << "Brand: " << brand << std::endl; }
};

// 派生类 Laptop，虚继承 Device
class Laptop : virtual public Device
{
public:
    Laptop(const std::string& brand_) : Device(brand_)
    {
    }
};

// 派生类 Tablet，虚继承 Device
class Tablet : virtual public Device
{
public:
    Tablet(const std::string& brand_) : Device(brand_)
    {
    }
};

// 派生类 Convertible
class Convertible : public Laptop, public Tablet
{
public:
    Convertible(const std::string& brand_) : Device(brand_), Laptop(brand_),
                                             Tablet(brand_)
    {
    }
};

//菱形继承问题

//Convertible继承laptop，tablet，有两份brand，解决这个问题就要laptop和tablet都虚继承Device
//通过使用虚继承（virtual public），确保 Convertible 类只有一份 Device 的成员。
//在 Convertible 的构造函数中，需要明确调用基类 Device 的构造函数，避免二义性。
//菱形继承（多重继承导致的重复基类）可以通过虚继承来解决，确保共享同一份基类成员。


//在 C++ 中，协变返回类型（Covariant Return Types）是一个与函数重写（Override）相关的概念。
//当一个派生类重写基类的虚函数时，协变返回类型允许派生类的函数返回一个从基类函数返回类型派生而来的类型。
//这玩意也是和虚函数一样是为了封装而搞的

// 基类
class Base {
public:
    virtual Base* clone() const {
        std::cout << "Base cloned." << std::endl;
        return new Base(*this);
    }

    virtual ~Base() {}
};

// 派生类
class Derived : public Base {
public:
    Derived* clone() const override { // 协变返回类型
        std::cout << "Derived cloned." << std::endl;
        return new Derived(*this);
    }
};



#endif //INTERVIEW_H
