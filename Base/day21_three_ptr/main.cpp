#include <iostream>
#include <memory>
#include <cstdio>
//智能指针有三种

// 1. std::unique_ptr
// 是一种独占所有权的智能指针，任何时刻只能有一个 unique_ptr 实例拥有对某个对象的所有权。
// 不能被**拷贝**，只能被**移动**。
// 一般拿来管理那些不能被拷贝的对象

// 2. std::shared_ptr
// 是一种共享所有权的智能指针，允许多个 shared_ptr 实例共享对同一个对象的所有权。
// 通过引用计数机制，管理资源的生命周期。

// 3. std::weak_ptr
// 是一种不拥有对象所有权的智能指针，用于观察但不影响对象的生命周期。
// 主要用于解决 shared_ptr 之间的循环引用问题。
// 特性：
// 非拥有所有权：不增加引用计数。
// 可从 shared_ptr 生成：通过 std::weak_ptr 可以访问 shared_ptr 管理的对象。
// 避免循环引用：适用于双向关联或观察者模式。  //避免循环引用这点很重要


class Test
{
public:
    Test(int val) : value(val)
    {
        std::cout << "Test Constructor: " << value << std::endl;
    }

    ~Test()
    {
        std::cout << "Test Destructor: " << value << std::endl;
    }

    void show() const
    {
        std::cout << "Value: " << value << std::endl;
    }

private:
    int value;
};


//循环引用
class B;

class A
{
public:
    std::shared_ptr<B> b_ptr; // A 持有 B 的 shared_ptr
    A()
    {
        std::cout << "A()" << std::endl;
    }

    ~A()
    {
        std::cout << "~A()" << std::endl;
    }
};

class B
{
public:
    std::weak_ptr<A> a_ptr;

    B()
    {
        std::cout << "B()" << std::endl;
    }

    ~B()
    {
        std::cout << "~B()" << std::endl;
    }
};


//自定义删除器
//智能指针允许我们在构造时传入对象以及一个自定义的删除器（deleter），
// 该删除器会在智能指针析构时被调用，用于释放资源。
// 一般在默认删除器不适合时写一个自定义删除器
// 这个自定义删除器是一个可调用对象

//可调用对象常见的有这几种：
//1. 函数指针
//2. 仿函数
//3. Lambda 表达式
//4. function
//5. std::bind进行绑定

struct FileDeleter
{
    //括号运算符重载，这是仿函数
    void operator()(FILE* fp) const
    {
        if (fp)
        {
            std::cout << "Closing file." << std::endl;
            fclose(fp);
        }
    }
};


int main()
{
    // std::unique_ptr<Test> test(new Test(1));
    // test->show();
    // // std::unique_ptr<Test> test2 = test; // 错误：不能拷贝 unique_ptr
    // std::unique_ptr<Test> test2 = std::move(test); // 正确：
    // test2->show();
    // std::unique_ptr<Test> test3 = std::make_unique<Test>(2);
    // // 使用 make_unique 创建 unique_ptr c++14用法,括号内填写构造函数参数
    // {
    //     std::shared_ptr<A> a = std::make_shared<A>();
    //     std::shared_ptr<B> b = std::make_shared<B>();
    //     a->b_ptr = b;
    //     b->a_ptr = a;
    //     // 两个指针都是shared_ptr
    //     // 这里会发生循环引用，导致 A 和 B 的析构函数不会被调用
    //     // 因为 A 和 B 的 shared_ptr 引用计数永远不会降到 0。
    //     // 解决方法是使用 std::weak_ptr 来打破循环引用（其中一个改成weak就好）。
    // }

    // {
    //     std::shared_ptr<FILE> fp(fopen("example.txt", "w"), FileDeleter());
    //     if (fp)
    //     {
    //         std::cout << "File opened successfully." << std::endl;
    //         // 使用 filePtr 进行文件操作
    //         fprintf(fp.get(), "Hello, World!\n");
    //     }
    // } // 生命周期到了，自动关闭文件

    {
        auto fileDeleter = [](FILE* fp)-> void
        {
            if (fp)
            {
                std::cout << "Closing file." << std::endl;
                fclose(fp);
            }
        };
        //uniqueptr传入删除器的话，尖括号中不仅要传入对象类型，还要传入删除器类型
        //删除器作为一个可调用对象，一般类型都很不好写，用decltype直接推导最好
        std::unique_ptr<FILE, decltype(fileDeleter)> filePtr(
            fopen("example.txt", "w"), fileDeleter);
        if (filePtr)
        {
            std::cout << "File opened successfully." << std::endl;
            fprintf(filePtr.get(), "Hello, Lambda!\n");
        }
    }

    std::cout << "Exiting main..." << std::endl;
    return 0;
}
