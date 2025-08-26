#include <iostream>
#include "SimpleSharedPtr.h"
//std::shared_ptr 是 C++ 标准库中功能强大的智能指针之一，提供了共享所有权的能力，使得多个指针可以共同管理同一个动态分配的对象。
//通过引用计数机制，shared_ptr 确保了对象在最后一个指针被销毁时自动释放，极大地简化了内存管理，防止了内存泄漏和悬挂指针问题。

//内存泄漏：new了之后没delete

//悬挂指针：delete了之后还在使用指针

//实现一个simple ptr,它包括以下功能：
//共享所有权：多个 SimpleSharedPtr 实例可以指向同一个对象，共享对该对象的所有权。
//自动管理生命周期：当最后一个 SimpleSharedPtr 被销毁或指向其他对象时，管理的对象被自动释放。
//引用计数：内部维护一个引用计数，记录有多少个 SimpleSharedPtr 实例指向同一个对象。


// 测试类
class Test
{
public:
    Test(int val) : value(val)
    {
        std::cout << "Test Constructor: " << value << std::endl;
    }

    ~Test() { std::cout << "Test Destructor: " << value << std::endl; }
    void show() const { std::cout << "Value: " << value << std::endl; }

private:
    int value;
};

int main()
{
    std::cout << "Creating default constructed shared_ptr..." << std::endl;
    SimpleSharedPtr<Test> ptr1; // 默认构造
    std::cout << "ptr1 use_count: " << ptr1.use_count() << std::endl;

    std::cout << "\nCreating shared_ptr with resource..." << std::endl;
    SimpleSharedPtr<Test> ptr2(new Test(100)); // 非默认构造
    std::cout << "ptr2 use_count: " << ptr2.use_count() << std::endl;
    ptr2->show();

    std::cout << "\nCopying ptr2 to ptr3..." << std::endl;
    SimpleSharedPtr<Test> ptr3 = ptr2; // 拷贝构造
    std::cout << "ptr2 use_count: " << ptr2.use_count() << std::endl;
    std::cout << "ptr3 use_count: " << ptr3.use_count() << std::endl;
    ptr3->show();

    std::cout << "\nAssigning ptr3 to ptr1..." << std::endl;
    ptr1 = ptr3; // 拷贝赋值
    std::cout << "ptr1 use_count: " << ptr1.use_count() << std::endl;
    std::cout << "ptr2 use_count: " << ptr2.use_count() << std::endl;
    std::cout << "ptr3 use_count: " << ptr3.use_count() << std::endl;

    std::cout << "\nResetting ptr2..." << std::endl;
    ptr2.reset(new Test(200)); // 重新指向新的对象
    std::cout << "ptr2 use_count: " << ptr2.use_count() << std::endl;
    ptr2->show();
    std::cout << "ptr1 use_count: " << ptr1.use_count() << std::endl;
    std::cout << "ptr3 use_count: " << ptr3.use_count() << std::endl;

    std::cout << "\nExiting scope..." << std::endl;
    // ptr2, ptr1, ptr3 离开作用域

    std::cout << "End of main." << std::endl;
    return 0;
}
