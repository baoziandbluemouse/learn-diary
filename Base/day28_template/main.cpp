#include <iostream>
#include <vector>
#include <string>
#include <list>
//C++ 模板（Templates）是现代 C++ 中强大而灵活的特性，支持泛型编程，使得代码更具复用性和类型安全性。
//模板不仅包括基本的函数模板和类模板，还涵盖了
//模板特化（全特化与偏特化）
//模板参数种类
//变参模板（Variadic Templates）
//模板元编程（Template Metaprogramming）
//SFINAE（Substitution Failure Is Not An Error）等高级内容。

//基础的函数模板与类模板：
template <typename T>
T maxValue(T a, T b)
{
    return (a > b) ? a : b;
}

template <typename T, typename U>
class Pair
{
public:
    T first;
    U second;

    Pair(T a, U b) : first(a), second(b)
    {
    }

    void print() const
    {
        std::cout << "Pair: " << first << ", " << second << std::endl;
    }
};

//尖括号内的是模板参数，模板参数内有类型参数和非类型参数，还有模板模板参数。

//类型参数就是typename T 这种形式的参数，它可以是任意类型。

//非类型参数是指模板参数中可以传入常量值，如整数、指针等。
template <typename T, std::size_t N>
class FixedArray
{
public:
    T data[N];

    T& operator[](std::size_t index)
    {
        return data[index];
    }

    void print() const
    {
        for (std::size_t i = 0; i < N; ++i)
            std::cout << data[i] << " ";
        std::cout << std::endl;
    }
};

//非类型参数必须是编译期常量,允许的类型包括整型、枚举、指针、引用等，但不包括浮点数和类类型。

//模板模板参数是指模板参数本身也是一个模板。
//这对于抽象容器和策略模式等场景非常有用。
//模板模板参数需要完全匹配被接受模板的参数列表。
//感觉就像嵌套差不多
template <typename T, template<typename ,typename >class Container>
class ContainerPrinter
{
public:
    void print(const Container<T, std::allocator<T>>& container)
    {
        for (const auto& elem : container)
            std::cout << elem << " ";
        std::cout << std::endl;
    }
};

//模板特化允许开发者为特定类型或类型组合提供专门的实现。
//当通用模板无法满足特定需求时，特化模板可以调整行为以处理特定的情况。
//C++ 支持全特化（Full Specialization）*和*偏特化（Partial Specialization），但需要注意的是，函数模板不支持偏特化，只能进行全特化。
// 通用模板
template <typename T>
class Printer
{
public:
    void print(const T& value)
    {
        std::cout << "General Printer: " << value << std::endl;
    }
};

//全特化,针对string进行
template <>
class Printer<std::string>
{
public:
    void print(const std::string& value)
    {
        std::cout << "String Printer: " << value << std::endl;
    }
};

//偏特化，使用前面的pair来作例子
// 类模板偏特化：当第二个类型是指针时
template <typename T, typename U>
class Pair<T, U*>
{
public:
    T first;
    U* second;

    Pair(T a, U* b) : first(a), second(b)
    {
    }

    void print() const
    {
        std::cout << "Pair with pointer: " << first << ", " << *second <<
            std::endl;
    }
};


//变参模板通常与递归相结合，通过递归地处理参数包，或者使用 折叠表达式（Fold Expressions） 来展开发参数包。

//当参数列表为空时，会进入一个空的printAll
void printAll()
{
    std::cout << std::endl;
}

template <typename T, typename... Args>
void printAll(const T& first, const Args&... args)
{
    std::cout << first << std::endl;
    printAll(args...); // 递归调用
}

//c++17引入了折叠表达式来使用参数列表
template <typename... Args>
void coutAll(const Args&... args)
{
    ((std::cout << args << std::endl), ...);
}

template <typename... Args>
auto sum(Args... args) -> decltype((args + ...))
{
    return (args + ...);
}

//一元折叠表达式
//对每个参数非操作，然后再将这些操作&&
//(!args && ...) 相当于 !a && !b && ...  将其抽象出来成为折叠表达式
template <typename... Args>
bool allNot(const Args&... args)
{
    return (!args && ...);
}

//二元折叠表达式
//二元左折叠（Binary Left Fold）：操作符从左至右结合，等价于 (((a op b) op c) op d)。
//二元右折叠（Binary Right Fold）：操作符从右至左结合，等价于 (a op (b op (c op d)))。

//左折叠
//((1 + 2) + 3) + 4 = 10
template <typename... Args>
auto sumleftall(Args... args) -> decltype((args + ...))
{
    return (args + ...);
}

//右折叠
//2 * (3 * 4) = 2 * 12 = 24。
template <typename... Args>
auto multiRightFold(const Args&... args) -> decltype((... * args))
{
    return (... * args);
}

//左移操作符的折叠(流插入)
template <typename... Args>
void printLeftFold(const Args&... args)
{
    (std::cout << ... << args) << std::endl; // 使用左折叠输出所有参数
}



int main()
{
    {
        // std::cout << maxValue<int>(1, 2) << std::endl;
        // std::cout << maxValue<double>(1.5, 2.5) << std::endl;
    }
    {
        // Pair<int, double> p1(1, 2.5);
        // p1.print();
        // Pair<std::string, std::string> p2("Hello", "World");
        // p2.print(); // 输出：Pair: Hello, World
        //
        // Pair<std::string, int> p3("Age", 30);
        // p3.print(); // 输出：Pair: Age, 30
    }
    {
        // std::vector<int> vec = {1, 2, 3, 4, 5};
        // std::list<int> lst = {10, 20, 30};
        //
        // ContainerPrinter<int, std::vector> vecPrinter;
        // vecPrinter.print(vec); // 输出：1 2 3 4 5
        //
        // ContainerPrinter<int, std::list> listPrinter;
        // listPrinter.print(lst); // 输出：10 20 30
    }
    {
        // Printer<int> intPrinter;
        // intPrinter.print(100); // 输出：General Printer: 100
        //
        // Printer<std::string> stringPrinter;
        // stringPrinter.print("Hello, World!");
        // 输出：String Printer: Hello, World!
    }
    {
        // Pair<int, double> p1(1, 2.5);
        // p1.print(); // 输出：Pair: 1, 2.5
        //
        // double value = 3.14;
        // Pair<std::string, double*> p2("Pi", &value);
        // p2.print(); // 输出：Pair with pointer: Pi, 3.14
    }
    {
        //printAll(10,20.5,"bac");
        //coutAll(10, 30.5, "bac", "hello", 42);
        // std::cout << sum(1, 2, 3, 4, 5) << std::endl; // 输出：15
        // std::cout << sum(1.5, 2.5, 3.0) << std::endl; // 输出：7
    }
    {
        printLeftFold(1, 2, 3, 4, 5);
    }

    return 0;
}
