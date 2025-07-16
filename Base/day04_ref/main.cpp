#include <iostream>
#include <string>
std::string foo() {
    return std::string("Hello, World!"); // 返回的临时字符串是一个右值
}
int main()
{
    system("chcp 65001");
    //定义变量
    // int a = 100;
    // int p = 200;
    // int &b = a; // b是a的引用
    // int *c = &a; //
    // int * const d = &a; // d是指向a的常量指针
    // const int *e = &a; // e是指向a的常量指针
    //d = &p; // 这行代码会报错，因为d是常量指针，不能改变指向
    //e = &p; // 这行代码是合法的，因为e是指向常量的指针，可以改变指向
    //输出变量地址
    // std::cout<<"a的地址是: "<<&a<<std::endl;
    // std::cout<<"b的地址是: "<<&b<<std::endl;
    // std::cout<<"c的地址是: "<<&c<<std::endl;
    // std::cout<<"d的地址是: "<<&d<<std::endl;
    // std::cout<<"e的地址是: "<<&e<<std::endl;
    //输出变量size
    // std::cout<<"a的大小是: "<<sizeof(a)<<std::endl;
    // std::cout<<"b的大小是: "<<sizeof(b)<<std::endl;
    // std::cout<<"c的大小是: "<<sizeof(c)<<std::endl;
    // std::cout<<"d的大小是: "<<sizeof(d)<<std::endl;
    // std::cout<<"e的大小是: "<<sizeof(e)<<std::endl;
    /*
     * 可以被修改的值叫作左值，不可以被修改的值叫作右值。
     * 右值有两种情况：函数返回值和字面量。
     */
    //直接绑定一个右值到右值引用（如int&& c = 20;）并不是右值引用的主要用途。
    //右值引用的主要用途是作为函数参数（实现移动语义）和返回值（允许链式调用等）。
    int&& o = 20; // c是整数字面量20的右值引用（但这种情况不常见，通常用于函数参数或返回值）
    o = 30; // 修改右值引用的值
    std::cout<< "o的值是: " << o << std::endl;
    int &m = o;
    m = 40; // 修改右值引用的值，实际上是修改o的值，因为m是o的别名
    std::cout<< "o的值是: " << o << std::endl;
    std::cout<< "m的值是: " << m << std::endl;
    std::string &&d = foo(); // d是foo()返回的临时字符串的右值引用
    std::cout << "d的值是: " << d << std::endl;
    return 0;
}
