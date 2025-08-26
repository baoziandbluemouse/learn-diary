#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <stack>

class DynamicArray
{
    //实现一个简单的动态数组
public:
    DynamicArray(): capacity(2), size(0),
                    data((int*)malloc(capacity * sizeof(int)))
    {
        if (data == nullptr) { throw std::bad_alloc(); }
    }

    ~DynamicArray() { free(data); }

    void add(int value)
    {
        if (size == capacity) { resize(capacity * 2); }
        data[size++] = value;
    }

    int get(size_t idx) const
    {
        if (idx >= size || idx < 0)
            throw std::out_of_range("index out of range");
        return data[idx];
    }

    size_t getSize() const { return size; }

private:
    void resize(size_t newCapacity)
    {
        int* temp = (int*)realloc(data, newCapacity * sizeof(int));
        if (temp == nullptr) { throw std::bad_alloc(); }
        data = temp;
        capacity = newCapacity;
    }

    size_t size;
    size_t capacity;
    int* data;
};

class MemoryPool
{
    //实现一个简单的内存池
    //MemoryPool 管理固定大小的内存块，避免频繁调用 malloc 和 free。
    //后续分配要使用“定位 new”在预分配的内存上构造对象。
    //void* mem1 = pool.allocate();
    //MyClass* obj1 = new(mem1) MyClass(100);
    //需要手动调用析构函数和将内存返回给内存池。
public:
    MemoryPool(size_t objectSize, size_t poolSize): objectSize(objectSize),
                                                    poolSize(poolSize)
    {
        pool = (char*)malloc(objectSize * poolSize);
        if (pool == nullptr) { throw std::bad_alloc(); }


        //初始化freeList
        for (size_t i = 0; i < poolSize; ++i)
        {
            freeList.push(pool + i * objectSize);
        }
    }

    ~MemoryPool() { free(pool); }

    void* allocate()
    {
        if (freeList.empty())
        {
            throw std::runtime_error("Memory pool exhausted");
        }
        void* ptr = freeList.top();
        freeList.pop();
        return ptr;
    }

    void deallocate(void* p) { freeList.push(p); }

private:
    size_t objectSize; //每个对象的大小
    size_t poolSize; //池子有几个对象
    char* pool;
    std::stack<void*> freeList;
};


int main()
{
    //c++与c的内存管理的区别
    //new 返回正确类型的指针，免去了强制类型转换。(malloc 返回 void*，需要显式转换为所需类型的指针)
    //new 和 delete 自动调用构造函数和析构函数。(malloc不会调用构造，free也是不调用析构)
    //也就是说用malloc去生成类，他只会分配空间，你要自己去调用构造函数，不然会乱码
    //在分配失败时，new 默认抛出 std::bad_alloc 异常，而 malloc 返回 nullptr。
    //new是支持多态的，malloc就没有考虑过多态的事情
    //注意new和delete配套，malloc和free配套
    //假如代码要涉及面向对象的编程，那么就使用C++风格的new和delete
    //但假如要考虑兼容C，那么就要用C风格的malloc和free


    //C再分配
    {
        int* arr = (int*)malloc(3 * sizeof(int));
        if (arr == nullptr)
        {
            std::cerr << "Memory allocation failed" << std::endl;
            return 1;
        }
        //初始化数组
        for (int i = 0; i < 3; i++)
            arr[i] = i + 1;
        std::cout << "Original array: ";
        for (int i = 0; i < 3; i++)
            std::cout << arr[i] << " ";

        std::cout << std::endl;

        //重写分配5个整数
        int* temp = (int*)realloc(arr, 5 * sizeof(int));
        //arr，之前的内存块，Newsize，新的大小
        if (temp == nullptr)
        {
            std::cerr << "Realloc failed" << std::endl;

            free(arr); // 释放原来的内存
            return 1;
        }
    }


    //RAII
    //是 C++ 中的一种编程惯用法，通过对象的生命周期管理资源，
    //确保资源在对象构造时获取，析构时释放，避免泄漏。（构造时分配内存，析构时释放内存，不需手动处理以免遗漏）
    //RAII的实现酒类似于C++的智能指针，使用对象的生命周期来管理资源。
    //这也是为了在出现异常的时候，能保证资源的回收
    return 0;
}
