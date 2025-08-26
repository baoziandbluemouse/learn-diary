#include <iostream>
#include <string>
#include <utility>
#include <type_traits>

//● 左值（lvalue）：
//○ 表示具有持久存储的对象。
//○ 可以出现在赋值语句的左侧。
//○ 可以被取地址（即，可以使用&运算符）。
//○ 示例：变量名、引用等。

//● 右值（rvalue）：
//○ 表示临时对象或没有持久存储的值。
//○ 通常出现在赋值语句的右侧。
//○ 不能被取地址。
//○ 示例：字面量、 临时对象、 表达式结果等。

//std::is_lvalue_reference<T>：判断类型T是否为左值引用。
//std::is_rvalue_reference<T>：判断类型T是否为右值引用。
//std::is_lvalue<T>（C++20起）：判断表达式是否为左值。
//std::is_rvalue<T>（C++20起）：判断表达式是否为右值。

//模板万能引用（也称为转发引用，英文为forwarding references）是C++11引入的一种引用类型，具有以下特点
//表现形式为T&&，其中T是模板参数。
//在特定条件下，编译器会将其解析为左值引用或右值引用。
//能够统一处理左值和右值，适用于泛型编程中的参数传递。
//当模板参数T被推导为普通类型时，T&&是右值引用。
//当模板参数T被推导为引用类型时，T&&会根据引用折叠规则解析为左值引用。

//折叠规则：
//& &、& &&、&& & 都折叠为 &（左值引用）。
//&& && 折叠为 &&（右值引用）。

void func(int& x)
{
    std::cout << "func(int&)" << std::endl;
}

void func(int&& x)
{
    std::cout << "func(int&&)" << std::endl;
}


//万能引用传进去左值或左值引用，T会是一个左值引用类型；而传进去右值或右值引用，T会是一个右值类型
//要注意的是，假如传进去一个右值引用变量，在表达式中右值引用变量都会当成左值来处理。
//因此，T&&会被解析为左值引用，而不是右值
//想要传右值引用，可以用std::move将其转换为右值引用。还有一种方式，就是forward原样转发
//至于x，传进去后要么是一个左值引用，要么是一个右值引用，取决于传进去左还是右
template <typename T>
void check_referenc(T&& x)
{
    std::cout << std::boolalpha;
    std::cout << "T is lvalue reference: " << std::is_lvalue_reference<T>::value
        << std::endl;
    std::cout << "T is rvalue reference: " << std::is_rvalue_reference<T>::value
        << std::endl;

    //在折叠规则下，无论T是右值还是右值引用，T&&都会被解析为右值引用。
    //而T如果是左值或左值引用，在折叠规则下，也会被解析为左值引用。
    //因此如果上面的右值引用为false，下面为true，那么T是右值，而两个都为true，就是右值引用
    std::cout << "T is rvalue : " << std::is_rvalue_reference<T&&>::value <<
        std::endl;
    std::cout << "x is lvalue reference: " << std::is_lvalue_reference<decltype(
        x)>::value << std::endl;
    std::cout << "x is rvalue reference: " << std::is_rvalue_reference<decltype(
        x)>::value << std::endl;
}

void process(int& x)
{
    std::cout << "process(int&)" << std::endl;
}

void process(int&& x)
{
    std::cout << "process(int&&)" << std::endl;
}

template <typename T>
void wraaper(T&& arg)
{
    process(std::forward<T>(arg));
    //如果传入左值，T是左值引用，进去process(int&)；
    //如果传入右值，T是右值的具体类型，进去process(int&&)

    //如果直接传arg，那么当传入右值时，T是具体类型，arg是右值引用变量
    //那么传进去表达式还是把arg当成左值来处理了
}


int main()
{
    system("chcp 65001");
    {
        // int a = 10; // a是一个左值
        // int& b = a; // b是a的左值引用
        // int&& c = 20; // c是一个右值引用，绑定到临时右值20
        // int d = a + 5; // (a + 5)是一个纯右值
        //
        // std::string s1 = "Hello"; // s1是一个左值
        // std::string s2 = std::string("World"); // std::string("World")是一个纯右值
        //
        // std::cout << "a: " << a << ", d: " << d << std::endl;
        // std::cout << "s1: " << s1 << ", s2: " << s2 << std::endl;
        //
        // // 检查类型
        // std::cout << std::boolalpha;
        // // 使用 decltype((a)) 获取 a 的类型，包括引用
        // // `(a)` 是一个左值表达式，所以 decltype((a)) 是 `int&`
        // // 如果单纯是decltype(a)，则是 `int`
        // std::cout << "a 是左值: " << std::is_lvalue_reference<decltype((a))>::value <<
        //     std::endl;
        // std::cout << "c 是右值引用: " << std::is_rvalue_reference<decltype(c)>::value <<
        //     std::endl;
    }
    {
        // int a = 5;
        // const int& ref = a;
        //
        // // 判断类型
        // std::cout << std::boolalpha;
        // // 使用 decltype((a)) 获取 a 的类型，包括引用
        // // `(a)` 是一个左值表达式，所以 decltype((a)) 是 `int&`
        // std::cout << "a 是左值: " << std::is_lvalue_reference<decltype((a))>::value
        //     << std::endl;
        // std::cout << "ref 是左值引用: " << std::is_lvalue_reference<decltype(ref
        // )>::value << std::endl;
        //
        // // 调用函数
        // // 利用函数重载来区分左值和右值引用
        // func(a); // 调用func(int&)
        // func(10); // 调用func(int&&)
    }
    {
        int a = 10;
        //check_referenc(a); //// T被推导为 int&， 因此 T&& -> int& && -> int&
        int&& c = 20; // c是一个右值引用，绑定到临时右值20
        //check_referenc(20);

        //命名的右值引用变量在表达式中被视为左值。那么T就是一个左值引用
        //c是一个右值引用变量，在表达式中被视为左值
        //check_referenc(c);
        //check_referenc(std::move(c)); // std::move(c)将c转换为右值
        //check_referenc(std::forward<int&&>(c));
        wraaper(a);
        wraaper(10);
    }
    return 0;
}
