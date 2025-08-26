#include <iostream>
#include "Drive.h"

int main()
{
    //多态使用的是指针，直接用基类无法实现多态，得用基类指针
    //Derive d(10, 20);
    //先调用基类的构造函数，再调用继承类的构造函数
    //确保基类的成员变量已经被初始化，继承类才能安全使用
    //析构时，先调用继承类的析构函数，再调用基类的析构函数
    //确保继承类的成员变量已经被销毁，基类才能安全销毁
    // d.DerivedFunc();
    // d.BaseFunc();
    // Base* bp = new Derive();
    // bp->display();
    //使用基类指针调用虚函数，实际调用的是子类的函数
    //因为虚函数的多态特性，基类指针指向子类
    //delete bp;
    Vehicle* v = new Car();
    v->startEngine();
    return 0;
}
