#include <iostream>
#include <mutex>
#include <thread>
#include "singleton.h"
//单例模式（Singleton Pattern）是一种创建型设计模式，
//旨在确保一个类在整个应用程序生命周期中仅且只有一个实例，并提供一个全局访问点以获取该实例。
//设计单例模式的主要原因和作用包括以下几个方面：

// 1. 控制实例数量：单例模式确保一个类只有一个实例，防止了多个实例的创建，节省了系统资源或者避免了状态不一致的问题。
// 2. 全局访问点：通过单例模式，可以提供一个全局访问,使得在程序的任何地方都可以方便地访问该实例。
// 3. 延迟实例化：单例模式通常采用延迟实例化的方式，即在第一次需要使用该实例时才创建它，避免了不必要的资源消耗。

//设计单例模式要考虑

//● 线程安全：在多线程环境下，需要确保单例实例的创建和访问是线程安全的，常用的方法有双重检查锁定（Double-Checked Locking）和使用静态内部类等。
//● 延迟初始化：根据需求选择是否采用延迟初始化，以平衡性能和资源利用。
//● 可测试性：单例模式可能会影响代码的可测试性，特别是在单元测试中，可能需要通过依赖注入等手段来替代单例实例。
//● 限制扩展：单例模式通过限制实例数量可能会限制类的扩展性，需谨慎使用。


int main()
{
    system("chcp 65001");
    // std::cout << "s1 addr is :" << &Single2::GetInst() << std::endl;
    // std::cout << "s2 addr is :" << &Single2::GetInst() << std::endl;

    std::mutex m;
    std::thread t1([&]()
    {
        SingleNet::GetInst();
        std::lock_guard<std::mutex> lock(m);
        std::cout << "s1 addr is :" << SingleNet::GetInst().get() << std::endl;
    });

    std::thread t2([&]()
    {
        SingleNet::GetInst();
        std::lock_guard<std::mutex> lock(m);
        std::cout << "s2 addr is :" << SingleNet::GetInst().get() << std::endl;
    });

    t1.join();
    t2.join();
    return 0;
}
