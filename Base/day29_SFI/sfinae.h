//
// Created by baozi on 2025/8/19.
//

#ifndef SFINAE_H
#define SFINAE_H
#include <iostream>
#include <type_traits>

//SFINAE通常与std::enable_if、模板特化、以及类型萃取等技术结合使用。

template <typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
//前面这一串都是print_type的返回值类型
//具体来说，enbale_if的第一个模板参数是一个布尔表达式，当该表达式为true时，type会定义为第二个模板参数的类型
//而is_integral会把T进行判断，看是不是整型，如果是，那么静态成员value就会是true
//所以这个函数当输入的T参数为int时，返回类型就会是void
print_type(T value)
{
    std::cout << "Integral type: " << value << std::endl;
}

template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, void>::type
print_type(T value)
{
    std::cout << "Floating point type: " << value << std::endl;
}

template <typename T>
typename std::enable_if<(std::is_same<T, char*>::value || std::is_same<
                            T, const char*>::value), void>::type
print_type(T value)
{
    std::cout << "C-style: " << value << std::endl;
}

//判断指针时要注意，如果想要c风格字符串不在其中，要加判断

template <typename T>
typename std::enable_if<(std::is_pointer<T>::value && !std::is_same<
                            T, char*>::value && !std::is_same<
                            T, const char*>::value), void>::type
print_type(T value)
{
    std::cout << "Pointer type" << std::endl;
}

template <typename T>
typename std::enable_if<(!std::is_integral<T>::value && !std::is_floating_point<
                                T>::value && !std::is_same<T, char*>::value && !
                            std::is_same<T, const char*>::value && !
                            std::is_pointer<T>::value), void>::type
print_type(T value)
{
    std::cout << "Other type: " << value << std::endl;
}

//c++20可以使用concept来实现类似的功能

template <typename T>
class has_foo
{
private:
    typedef char yes[1];
    typedef char no[2];

    template <typename U, void(U::*)()>
    struct SFINAE
    {
    }; //接收一个类型U和一个成员函数指针

    template <typename U>
    static yes& test(SFINAE<U, &U::foo>*); //尝试匹配有foo成员函数的类型

    template <typename U>
    static no& test(...); //匹配没有foo成员函数的类型
public:
    static constexpr bool value = sizeof(test<T>(nullptr)) == sizeof(yes);
    //此处test没做定义，只是写了个声明，事实上也不需要定义再用
    //我们只需要用test做一个检测去匹配就好,此处test并不是真的被调用了
    //如果匹配成功，test<T>(nullptr)的返回类型是yes，否则是no
};

template <typename T>
typename std::enable_if<has_foo<T>::value, void>::type
call_foo(T& obj)
{
    obj.foo(); //如果T有foo成员函数，则调用它
    std::cout << "foo() called." << std::endl;
}

class withFoo
{
public:
    void foo()
    {
        std::cout << "foo() called." << std::endl;
    }
};

class withoutFoo
{
};


// 1. 定义一个 Trait 用于检测 T 是否有非 void 的 `value_type`
template <typename T, typename = void>
struct has_non_void_value_type : std::false_type
{
};

// 仅当 T 有 `value_type` 且 `value_type` 不是 void 时，特化为 std::true_type
template <typename T>
struct has_non_void_value_type<T, std::enable_if_t<!std::is_void_v<typename
                                   T::value_type>>> : std::true_type
{
};

// 2. 定义 TypePrinter 主模板，使用一个布尔参数控制特化
template <typename T, bool HasValueType = has_non_void_value_type<T>::value>
struct TypePrinter;

// 3. 特化：当 HasValueType 为 true 时，表示 T 有非 void 的 `value_type`
template <typename T>
struct TypePrinter<T, true>
{
    static void print()
    {
        std::cout << "T has a member type 'value_type'." << std::endl;
    }
};

// 特化：当 HasValueType 为 false 时，表示 T 没有 `value_type` 或 `value_type` 是 void
template <typename T>
struct TypePrinter<T, false>
{
    static void print()
    {
        std::cout << "hello world! T does not have a member type 'value_type'."
            << std::endl;
    }
};

// 测试结构体
struct WithValueType
{
    using value_type = int;
};

struct WithoutValueType
{
};

struct WithVoidValueType
{
    using value_type = void;
};


#endif //SFINAE_H
