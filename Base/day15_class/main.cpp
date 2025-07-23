#include <iostream>

class Example
{
public:
    // 默认构造函数
    Example() : data_(0) { std::cout << "Default constructor called.\n"; }

    // 参数化构造函数
    Example(const int data) : data_(data)
    {
        std::cout << "Parameterized constructor called with data = " << data_ <<
            ".\n";
    }

    // 拷贝构造函数
    // 拷贝构造一定要传引用，否则会陷入无限递归
    // const也尽量写上，安全性
    // 拷贝构造的问题是成员变量会有不适合进行拷贝的。
    // 例如线程（根本没有拷贝构造，但有移动构造），指针（会有深拷贝浅拷贝问题）之类
    // 如果原类在复制后就不需要了，这也可以不用拷贝构造而是用移动构造，这是C++11引入的特性
    Example(const Example& other) : data_(other.data_)
    {
        std::cout << "Copy constructor called.\n";
    }

    // 移动构造函数
    // 右值引用（&&）是C++11引入的特性，用于实现移动语义和完美转发
    // 可以绑定到“将要被销毁的临时对象”或“没有名字的右值”上，比如字面值、表达式结果、临时对象等
    Example(Example&& other) : data_(std::move(other.data_))
    {
        other.data_ = 0;
        std::cout << "Move constructor called.\n";
    }

    // 析构函数
    ~Example()
    {
        std::cout << "Destructor called for data = " << data_ << ".\n";
    }

private:
    int data_;
};


int main()
{
    Example ex1; // 调用默认构造函数
    Example ex2(42); // 调用参数化构造函数
    Example ex3 = ex2; // 调用拷贝构造函数
    Example ex4(std::move(ex2)); // 调用移动构造函数(c++11)
    //移动构造后，原类，即ex2仍然会存在，最终也会调用析构函数

    //关于初始化列表，假如类中有一个引用类型的成员变量，不能使用默认的构造函数
    //并且构造函数必须用初始化列表来初始化引用类型的成员变量
    //不能写在函数体内
    //原因是因为函数体内只涉及赋值操作
    // 而引用类型的成员变量必须在对象创建时就被初始化
    //初始化列表可以做到对成员变量初始化，再传入括号中的参数
    //初始化列表的初始化的顺序是按照成员变量在类中声明的顺序，而不是在初始化列表中的顺序

    //static类型的成员变量也是不在构造函数体内初始化的，静态成员隶属于类而不是单一的对象
    //静态成员变量一般在非内连文件中初始化（即cpp）
    //静态成员函数可以访问静态成员变量，但不能访问非静态成员变量

    //深拷贝，浅拷贝问题主要是对于指针类型的成员变量会出现
    //即有出现堆内存分配的情况，就要考虑深拷贝
    //浅拷贝是指直接复制指针的值，使多个对象共享同一块内存（小心双重释放问题）
    //(实现：直接将新指针指向原指针所指向的内存地址)
    //深拷贝是指复制指针所指向的内存内容，使每个对象都有自己的内存空间
    //（实现：为新指针分配新的内存空间，然后用解引用赋值） *newdata = *(ohter.data);
    //实现哪种拷贝方式取决于类的设计和需求,关键是知道自己在写什么
    //有些类型根本不支持拷贝，就比如thread，这就只能浅拷贝
    //移动构造的时候也是要注意这个问题，堆空间应该是要自己再开辟，然后赋值时用move来赋值
    return 0;
}
