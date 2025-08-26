#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
//什么是可调用对象：一个对象可以像函数一样使用
//C++ 提供了多种方式来表示和操作可调用对象
//包括传统的函数指针、仿函数（Functors）、Lambda表达式、std::function 和 std::bind 等。
//主要在处理回调、事件驱动编程和函数式编程时表现尤为出色。

//1. 函数指针
//函数指针是C++中最基本的可调用对象之一，用于指向普通函数和静态成员函数。
//注：如果要指向非静态成员函数，参数需要增加一个类实例的引用或指针,具体看day18_virtual

// 定义函数指针类型
int (*funcPtr)(int, int);
// 定义一个普通函数
int add(int a, int b)
{
    return a + b;
}

//优点：
//简单直观，适用于简单的回调函数。
//缺点:
//不能捕获上下文（如lambda中的闭包）。
//语法相对复杂，尤其是指针的声明和使用。


//2. 仿函数（Functors）
//仿函数（Functors），又称函数对象（Function Objects）
//是在C++中重载了 operator() 的类或结构体实例。
//仿函数不仅可以像普通函数一样被调用，还能携带状态，提供更大的灵活性和功能性。
//优点：
//携带状态： 仿函数可以拥有内部状态，通过成员变量存储数据，使其在调用时具备上下文信息。
//灵活性高： 可以根据需要添加更多的成员函数和变量，扩展功能。
//性能优化： 编译器可以对仿函数进行优化，例如内联展开，提高执行效率。

//仿函数不仅可以执行简单的计算，还可以进行复杂的操作。
//例如，实现一个可变的仿函数，用于累加多个值。(用一个成员变量存储要加的值)(括号重载用来加值)
//许多标准库算法可以接受仿函数作为参数，使得算法的行为更加灵活和可定制。(就比如sort)

//定义一个仿函数类
class Adder
{
public:
    int to_add;
    //构造函数
    Adder(int add): to_add(add)
    {
    }

    int operator()(int x)
    {
        return x + to_add;
    }
};

//仿函数与模板相结合，可以实现高度通用和可复用的代码。例如，编写一个通用的比较仿函数。
// 通用比较仿函数
template <typename T>
struct Compare
{
    bool operator()(const T& a, const T& b) const
    {
        return a < b;
    }
};

//何时使用仿函数？
//需要携带状态时： 当回调函数需要维护内部状态时，仿函数是理想选择。
//复杂操作： 当简单的函数指针或Lambda难以表达复杂逻辑时。
//性能关键场景： 由于仿函数可以被编译器优化，适用于性能敏感的代码。

//Lambda表达式是C++11引入的一种轻量级函数对象，允许在代码中定义匿名函数。
//它们可以捕获周围的变量，具有更强的表达能力
//语法：
//[captures](parameters) -> return_type {
// 函数体
//captures: 捕获外部变量的方式，可以是值捕获、引用捕获。
//parameters: 函数参数列表。
//return_type: 返回类型，可以省略，编译器会自动推断。
//}

//值捕获得到的是变量的副本，修改不会影响原变量。 [=]可以直接值捕获所有外部变量。
//引用捕获允许直接修改外部变量。[&]可以直接引用捕获所有外部变量。


//lambda还可以捕获类的成员变量和成员函数
class Processor
{
public:
    Processor(int threshold) : threshold(threshold)
    {
    }

    void process(std::vector<int>& data)
    {
        std::cout << "before processing: ";
        for (auto num : data) std::cout << num << " ";
        std::cout << std::endl;

        // 使用Lambda表达式进行过滤
        data.erase(std::remove_if(data.begin(), data.end(),
                                  [this](int n) -> bool
                                  {
                                      //直接把类捕获了
                                      return n < threshold;
                                  }), data.end());

        std::cout << "after processing: ";
        for (auto num : data) std::cout << num << " ";
        std::cout << std::endl;
    }

private:
    int threshold;
};

//std::function 是C++11提供的一个通用的可调用包装器，能够封装任何可调用对象，
//包括普通函数、Lambda表达式、函数对象以及绑定表达式。
//它实现了类型擦除，使得不同类型的可调用对象可以通过统一的接口进行操作。
//类型擦除就是他能接收各种类型的可调用对象，而不需要知道具体类型。

struct Multiply
{
    int operator()(int a, int b)
    {
        return a * b;
    }
};


//回调机制
using Callback = std::function<void(int)>;

//触发事件的函数
void triggerEvent(Callback cb, int value)
{
    //事件发生，调用回调
    cb(value);
}


//
//std::bind 是C++11中提供的一个函数适配器
//用于绑定函数或可调用对象的部分参数，生成一个新的可调用对象。
//它允许提前固定某些参数，简化函数调用或适应接口需求。

void print(int a, int b, int c)
{
    std::cout << a << " " << b << " " << c << std::endl;
}


class Calculator
{
public:
    int multiply(int a, int b) const
    {
        return a * b;
    }
};

class Logger
{
public:
    static void log(const std::string& message)
    {
        std::cout << "Log: " << message << std::endl;
    }
};


int main()
{
    //{
    //     // 使用函数指针调用函数
    //     funcPtr = &add; //加不加&都行
    //     std::cout << "Function Pointer: " << funcPtr(2, 3) << std::endl;
    // }
    // {
    //     //使用仿函数类调用函数
    //     Adder adder(5);
    //     std::cout << "Functor: " << adder(10) << std::endl;
    // }
    // {
    //     std::vector<int> numbers = {5, 2, 8, 1, 9};
    //
    //     // 使用仿函数进行排序
    //     std::sort(numbers.begin(), numbers.end(), Compare<int>());
    //
    //     std::cout << "numbers after sort: ";
    //     for (auto num : numbers)
    //     {
    //         std::cout << num << " "; // 输出: 1 2 5 8 9
    //     }
    //     std::cout << std::endl;
    // }
    // {
    //     int threshold = 5;
    //     std::vector<int> vec = {1, 6, 3, 8, 2, 7};
    //     // 使用lambda表达式进行过滤
    //     vec.erase(std::remove_if(vec.begin(), vec.end(),
    //                              [threshold](int n) -> bool
    //                              {
    //                                  return n < threshold;
    //                              }), vec.end());
    //     // 输出结果
    //     for (auto n : vec)
    //     {
    //         std::cout << n << " "; // 输出: 6 8 7
    //     }
    // }
    // {
    //     //默认情况下，Lambda表达式是不可变的（const）。
    //     //通过mutable关键字，可以允许修改捕获的变量副本
    //     //但是如果用引用捕获，就不需要mutable就可以修改外部变量
    //     int count = 0;
    //     auto increment = [count]() mutable
    //     {
    //         count++;
    //         std::cout << "Count inside lambda: " << count << std::endl;
    //     };
    //     increment(); // 输出: Count inside lambda: 1
    //     increment(); // 输出: Count inside lambda: 2
    // }
    {
        //lambda的一个用处就是捕获智能指针（值捕获）,能保证即使原先那个智能指针被销毁了
        //lambda捕获了他，得到的副本会一直存在，直到函数结束。
        //这在异步，线程，回调中非常有用
        //配合智能指针，这是lambda的一个最重要的用处
    }
    {
        // std::vector<int> numbers = {1, 6, 3, 8, 2, 7};
        // Processor proc(5);
        // proc.process(numbers);
        // /*
        // 输出:
        // 处理前数据: 1 6 3 8 2 7
        // 处理后数据: 6 8 7
        // */
    }
    {
        // //封装普通函数
        // std::function<int(int, int)> func = add;
        // std::cout << "Add: " << func(5, 6) << std::endl;
        //
        // //封装仿函数
        // Multiply multiply;
        // std::function<int(int, int)> func2 = multiply;
        // std::cout << "Multiply: " << func2(5, 6) << std::endl;
        //
        // //封装Lambda表达式
        // std::function<int(int, int)> func3 = [](int a, int b)
        // {
        //     return a - b;
        // };
        // std::cout << "Substract: " << func3(10, 4) << std::endl;
        //相比于直接使用函数指针或Lambda，std::function 可能带来一定的性能开销，尤其是在频繁调用时。

        //function用法与场景
        //回调函数的传递。
        //事件处理系统。
        //策略模式的实现。
    }
    {
        //使用lambda作为回调
        // triggerEvent([](int x)
        // {
        //     std::cout << "Callback triggered with value: " << x << std::endl;
        // }, 42);
        //
        // //使用仿函数作为回调
        // struct Printer
        // {
        //     void operator()(int x) const
        //     {
        //         std::cout << "Print value: " << x << std::endl;
        //     }
        // } printer;
        // triggerEvent(printer, 100); // 输出: Print value: 100
    }
    {
        //function还可以存在stl容器中，便于管理和调用
        // std::vector<std::function<int(int, int)>> operations;
        //
        // // 添加不同类型的可调用对象
        // operations.emplace_back(add); // 普通函数
        // operations.emplace_back(Multiply()); // 仿函数
        // operations.emplace_back([](int a, int b) -> int
        // {
        //     return a - b;
        // }); // Lambda
        //
        // // 执行所有操作
        // for (auto& op : operations)
        // {
        //     std::cout << op(10, 5) << " "; // 输出: 15 50 5
        // }
        // std::cout << std::endl;
    }
    {
        // 绑定第一个参数为10，生成新的函数对象
        auto add10 = std::bind(add, 10, std::placeholders::_1);
        //add第一个参数绑定为10，第二个参数填了个占位符，这意味着留空
        std::cout << "10 + 5 = " << add10(5) << std::endl; // 输出: 10 + 5 = 15
        //std::bind 使用占位符来表示未绑定的参数，这些占位符决定了在生成的新函数对象中如何传递参数。
        //占位符 std::placeholders::_1 表示第一个未绑定的参数，_2 表示第二个未绑定的参数，以此类推。
        //注意，这个1代表的是第一个未绑定的参数，而不是函数的第一个参数。
        auto reverse_print = std::bind(print, std::placeholders::_3,
                                       std::placeholders::_2,
                                       std::placeholders::_1);
        reverse_print(1, 2, 3); // 输出: 3 2 1
    }
    {
        //bind还可以绑定成员函数，但是需要一个类实例
        Calculator calc;
        //第一个是类成员函数，第二个是对象
        auto multiplyBy5 = std::bind(&Calculator::multiply, &calc, 5,
                                     std::placeholders::_1);
        //类的成员函数，其实第一个参数是一个隐式的参数，是类对象的地址，之前day18_virtual中讲过
        std::cout << "5*3 =" << multiplyBy5(3) << std::endl; // 输出: 5*3 = 15

        //lambda表达式绑定
        auto multiplyBy10 = [&calc](int x)
        {
            return calc.multiply(10, x);
        };
        std::cout << "10*4 = " << multiplyBy10(4) << std::endl; // 输出: 10*4 = 40
    }

    {
        //绑定静态成员函数
        // 使用std::bind绑定静态成员函数
        auto logFunc = std::bind(&Logger::log, std::placeholders::_1);

        logFunc("This is a static log message.");
        // 输出: Log: This is a static log message.
    }

    return 0;
}
