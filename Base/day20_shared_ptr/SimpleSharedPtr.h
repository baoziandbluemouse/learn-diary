//
// Created by baozi on 2025/8/5.
//

#ifndef SIMPLESHAREDPTR_H
#define SIMPLESHAREDPTR_H


//为了实现引用计数机制，SimpleSharedPtr 需要一个控制块（Control Block），它包含：
//1. 引用计数：记录有多少个 SimpleSharedPtr 实例指向同一个对象。
//2. 指向对象的指针：指向实际管理的对象。

//控制块通常与被管理对象一起被分配，但为了简化实现，将它们独立管理。


struct ControlBlock
{
    int ref_count; // 引用计数
    //可扩展包括自定义删除器等
    ControlBlock(): ref_count(1)
    {
    }
};


//SimpleSharedPtr 是一个模板类，模板参数 T 表示它所管理的对象类型。
//模板类的实现必须全部放在头文件中，否则链接时找不到具体实例化代码。

template <typename T>
class SimpleSharedPtr
{
private:
    T* ptr; // 指向实际管理的对象
    ControlBlock* control; //指向控制块
    //辅助函数
    void release();

public:
    //构造，析构，拷贝与移动操作，操作符重载等
    //默认构造
    SimpleSharedPtr(): ptr(nullptr), control(nullptr)
    {
    }

    //参数化构造
    explicit SimpleSharedPtr(T* ptr);
    //析构
    ~SimpleSharedPtr();
    //拷贝构造
    SimpleSharedPtr(const SimpleSharedPtr& other);
    //拷贝赋值
    SimpleSharedPtr& operator=(const SimpleSharedPtr& other);
    //移动构造
    //移动语义允许资源所有权从一个 SimpleSharedPtr 转移到另一个，而不增加引用计数。
    //noexcept关键字：移动失败不报异常
    SimpleSharedPtr(SimpleSharedPtr&& other) noexcept;
    //移动赋值
    SimpleSharedPtr& operator=(SimpleSharedPtr&& other) noexcept;

    //重载 * 和 -> 操作符，以便像使用原生指针一样使用 SimpleSharedPtr。
    //不然可能就得用s2.ptr->member这种方式来访问成员函数了,太麻烦
    //解引用也是这样，能直接对s2解引用得到对象
    //解引用操作符
    T& operator*() const;
    //箭头操作符
    T* operator->() const;
    //获取引用计数
    int use_count() const;
    //获取裸指针
    T* get() const;
    //重置指针
    void reset(T* p = nullptr);
};

template <typename T>
void SimpleSharedPtr<T>::release()
{
    //如果控制块存在，减少引用计数，再看看是否为0,为0就释放内存
    if (control)
    {
        //存在计数器
        --control->ref_count;
        if (control->ref_count == 0)
        {
            delete ptr;
            delete control;
        }
    }
    ptr = nullptr;
    control = nullptr;
}

template <typename T>
SimpleSharedPtr<T>::SimpleSharedPtr(T* ptr): ptr(ptr)
{
    //如果传入指针不为空，则创建控制块并初始化引用计数
    if (ptr)
        control = new ControlBlock();
    else
        control = nullptr;
}

template <typename T>
SimpleSharedPtr<T>::~SimpleSharedPtr()
{
    //如果计数器没有为0，那么就减少计数器
    //如果计数器为0，那么就释放内存
    if (ptr) { release(); }
}

template <typename T>
SimpleSharedPtr<
    T>::SimpleSharedPtr(const SimpleSharedPtr& other): ptr(other.ptr),
    control(other.control)
{
    //假设有s1和s2，s2拷贝构造s1,那么两个指针都指向同一个对象
    if (control)
    {
        //如果有计数器
        ++control->ref_count; //增加引用计数
    }
}

template <typename T>
SimpleSharedPtr<T>& SimpleSharedPtr<T>::operator=(const SimpleSharedPtr& other)
{
    //拷贝赋值涉及s1和s2,如果s1和s2指向同一个对象，那么不需要做任何操作，返回就好了，但不同的话，假设要让s2=s1
    //那么就要先减少s2的引用计数(如果为0就释放），然后增加s1的引用计数，最后让s2指向s1的对象
    if (this != &other)
    {
        //释放当前资源（具体是释放还是减少在这个函数里判断）
        release();
        //复制
        ptr = other.ptr;
        control = other.control;
        if (control) { control->ref_count++; }
    }
    return *this;
}

template <typename T>
SimpleSharedPtr<
    T>::SimpleSharedPtr(SimpleSharedPtr&& other) noexcept: ptr(other.ptr),
    control(other.control)
{
    //移动构造，直接将其他的指针和控制块转移过来
    other.ptr = nullptr; //将other的指针置空(不置空，这个other在析构的时候会影响释放）
    other.control = nullptr; //将other的控制块置空
}

template <typename T>
SimpleSharedPtr<T>& SimpleSharedPtr<T>::operator=(
    SimpleSharedPtr&& other) noexcept
{
    //和拷贝赋值差不多
    if (this != &other)
    {
        //释放当前资源
        release();
        //转移资源（接管other的资源）
        ptr = other.ptr;
        control = other.control;
        other.ptr = nullptr;
        other.control = nullptr; //将other的指针和控制块置空
    }
    return *this;
}

template <typename T>
T& SimpleSharedPtr<T>::operator*() const
{
    return *ptr; //解引用操作符，返回指向的对象
}

template <typename T>
T* SimpleSharedPtr<T>::operator->() const { return ptr; }

template <typename T>
int SimpleSharedPtr<T>::use_count() const
{
    return control ? control->ref_count : 0; //返回引用计数
}

template <typename T>
T* SimpleSharedPtr<T>::get() const { return ptr; }

template <typename T>
void SimpleSharedPtr<T>::reset(T* p)
{
    if (ptr == p)
    {
        //如果新指针和当前指针相同，不需要做任何操作
        return;
    }
    //释放当前资源
    release();
    ptr = p;
    if (p)
    {
        //新指针，创建一个新block
        control = new ControlBlock();
    }
    else { control = nullptr; }
}


#endif //SIMPLESHAREDPTR_H
