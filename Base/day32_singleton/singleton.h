//
// Created by baozi on 2025/8/23.
//

#ifndef SINGLETON_H
#define SINGLETON_H
#include <iostream>
#include <mutex>
#include <memory>


//局部静态变量
//最简单一款
class Single2
{
private:
    Single2() = default;
    Single2(const Single2&) = delete;
    Single2& operator=(const Single2&) = delete;

public:
    ~Single2()
    {
        std::cout << "~Single2()" << std::endl;
    }

    static Single2& GetInst()
    {
        static Single2 single; //只会创建一次，在C++11以后，被优化为了线程安全的,c++98时不是
        return single;
    }
};

//静态成员变量指针式（饿汉式）
//这种方式依靠静态成员提前初始化来保证生成的单例是唯一的
//具体来说就是在多线程调用前，就提前初始化好
class SignleHungry
{
private:
    SignleHungry() = default;
    SignleHungry(const SignleHungry&) = delete;
    SignleHungry& operator=(const SignleHungry&) = delete;
    static SignleHungry* instance; //静态成员变量的初始化要在非内连文件中进行，简单来说就是去cpp进行

public:
    ~SignleHungry()
    {
        if (instance != nullptr)
        {
            delete instance;
            instance = nullptr;
        }
        std::cout << "~SignleHungry()" << std::endl;
    }

    static SignleHungry* GetInst()
    {
        if (instance == nullptr)
        {
            instance = new SignleHungry();
        }
        return instance;
    }
};

//静态成员变量指针式（懒汉式）
//这种方式的资源用到了才开始初始化
//这种方式需要考虑线程安全问题,可以用锁，也可以用once_flag
//但是用锁的话，会极大影响性能，完全导致并发性能下降
//就有人提出用双重锁定优化,但这种方法有极大安全隐患
//具体原因是因为编译器不同可能导致new的做法不同
//new分为三步：1.开辟空间 2.调用构造 3.赋值给指针
//但有的编译器会把2和3的顺序调换，同时我们是并发的，这就有可能出现指针不为空，但对象还没构造完毕
//c++提出了一个引进的方法，使用once_flag,这玩意在多个线程中只会执行一次,一般配套一个call_once使用
//call_once调用一次once_flag后，下次再遇到once_flag，就不会继续调用后面的可调用对象了
class SingleLazy
{
private:
    SingleLazy() = default;
    SingleLazy(const SingleLazy&) = delete;
    SingleLazy& operator=(const SingleLazy&) = delete;
    static SingleLazy* instance;
    static std::mutex _mutex;

public:
    ~SingleLazy()
    {
        std::cout << "~SingleLazy()" << std::endl;
    }

    static SingleLazy* GetInst()
    {
        //双重锁定
        if (instance == nullptr)
        {
            if (instance != nullptr)
            {
                return instance;
            }
            _mutex.lock();
            if (instance != nullptr)
            {
                _mutex.unlock();
                return instance;
            }
            instance = new SingleLazy();
            _mutex.unlock();
        }
        return instance;
    }
};

class Singleflag
{
private:
    Singleflag() = default;
    Singleflag(const Singleflag&) = delete;
    Singleflag& operator=(const Singleflag&) = delete;
    static std::shared_ptr<Singleflag> instance;

public:
    ~Singleflag()
    {
        std::cout << "~Singleflag()" << std::endl;
    }

    static std::shared_ptr<Singleflag> GetInst()
    {
        static std::once_flag _flag;
        std::call_once(_flag, []()
        {
            instance = std::shared_ptr<Singleflag>(new Singleflag());
            //不能使用make_shared,因为构造函数是私有的.无法访问
        });
        return instance;
    }
};

//通用的单例模板类(CRTP)
//CRTP是一种将派生类作为模板参数传递给基类的技术，即一个类继承自一个以自身为模板参数的基类。
//这种模式常用于实现静态多态、接口的默认实现、编译时策略选择等。
template <typename T>
class Singleton
{
protected:
    Singleton() = default;
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    static std::shared_ptr<T> instance;
    //虽然是静态成员，但是他是模板类，就必须在.h文件初始化
public:
    ~Singleton()
    {
        std::cout << "~Singleton()" << std::endl;
    }

    static std::shared_ptr<T> GetInst()
    {
        static std::once_flag _flag;
        std::call_once(_flag, []()
        {
            instance = std::shared_ptr<T>(new T());
            //不能使用make_shared,因为构造函数是私有的.无法访问
        });
        return instance;
    }
};

template <typename T>
std::shared_ptr<T> Singleton<T>::instance = nullptr;

class SingleNet : public Singleton<SingleNet>
{
private:
    SingleNet() = default;
    //要注意，我们这个基类得和派生类是友元关系，不然没法访问派生类的私有构造函数
    friend class Singleton<SingleNet>;

public:
    ~SingleNet()
    {
        std::cout << "~SingleNet()" << std::endl;
    }
};


#endif //SINGLETON_H
