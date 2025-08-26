//
// Created by baozi on 2025/8/20.
//

#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>
#include <type_traits>

//通用模板类
template <typename T, typename Enable = void>
class Logger
{
public:
    static void log(const T& value)
    {
        std::cout << "General value: " << value << std::endl;
    }
};

//类模板偏特化，当T是指针类型
template <typename T>
class Logger<T, typename std::enable_if<std::is_pointer<T>::value>::type>
{
public:
    static void log(const T& value)
    {
        if (value)
        {
            std::cout << "Logging pointer value: " << *value << std::endl;
        }
        else
        {
            std::cout << "Logging pointer value: nullptr" << std::endl;
        }
    }
};

//类模板全特化，当T是std::string类型
template <>
class Logger<std::string>
{
public:
    static void log(const std::string& value)
    {
        std::cout << "Logging string value: " << value << std::endl;
    }
};

//函数模板，用于递归调用Logger::log
template <typename T>
void logOne(const T& value)
{
    Logger<T>::log(value);
}

//使用可变参数列表接收多个参数
template <typename... Args>
void logAll(const Args&... args)
{
    (logOne(args), ...);
}

template <int N>
struct Factorial
{
    static const int value = N * Factorial<N - 1>::value;
    //在 C++ 中，静态成员变量的声明与定义有以下基本规则：
    //1. 在类内部声明静态成员变量，告诉编译器该类包含这个静态成员。
    //2. 在类外部对静态成员变量进行定义，分配存储空间。

    //如果不加const的static成员，必须在类外做初始化
    //如果加了const，这个成员只能当成一个常量成员使用,可以在类里面定义
    //这些成员只是进行了声明，不过由于c++特性，声明同时告诉了一个值
    //没有进行定义，不会给这些成员空间
    //总而言之，这个会影响到取地址，如果想要取地址，那么那个变量就一定要定义

    //从 C++17 开始，引入了 内联变量（inline variables），使得在类内定义静态成员变量变得更加灵活：
};

//最后会有一个N=0的情况，写个特例化版本来暂停
template <>
struct Factorial<0>
{
    static const int value = 1;
};

//通用版本的静态成员定义可以写在h文件内
//全特化版本的静态成员定义要写在cpp内

template <int N>
struct Fibonacci
{
    inline static const long long value = Fibonacci<N - 1>::value + Fibonacci<N
        - 2>::value;
};

// 递归终止
template <>
struct Fibonacci<0>
{
    inline static const long long value = 0;
};

template <>
struct Fibonacci<1>
{
    inline static const long long value = 1;
};

// 检测是否可以对T类型进行加法操作
template <typename T, typename = void>
struct is_addable : std::false_type
{
};

// 如果T类型不能进行加法操作，那么就会匹配到这个通用版本


// 如果T类型可以进行加法操作，那么就会匹配到这个特化版本
//declval可以用于不实际创建一个T对象的情况下，创建一个T类型的右值引用
template <typename T>
struct is_addable<T, decltype(void(std::declval<T>() + std::declval<T>())
                  )> : std::true_type
    //如果匹配成功了，那么就让他继承true_type，成员value就是true
{
};

// 基本递归模板
template <int... Ns>
struct Sum;

// 递归终止
template <>
struct Sum<>
{
    static const int value = 0;
};

// 递归定义
template <int N, int... Ns>
struct Sum<N, Ns...>
{
    static const int value = N + Sum<Ns...>::value;
};

//定义类型列表
template <typename... Ts>
struct TypeList
{
};


//获取类型列表中第N个类型
template <typename List, std::size_t N>
struct TypeAt;

template <typename Head, typename... Tail>
struct TypeAt<TypeList<Head, Tail...>, 0>
{
    using type = Head;
};

template <typename Head, typename... Tail, std::size_t N>
struct TypeAt<TypeList<Head, Tail...>, N>
{
    using type = typename TypeAt<TypeList<Tail...>, N - 1>::type;
};

#endif //LOGGER_H
