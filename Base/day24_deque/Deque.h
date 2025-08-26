//
// Created by baozi on 2025/8/10.
//

#ifndef DEQUE_H
#define DEQUE_H
#include <iostream>
#include <stdexcept>
#include <iterator>


template <typename T>
class Deque
{
private:
    T* buffer; //内部缓冲区
    size_t capacity; //缓冲区容量
    size_t front_idx; //前端索引
    size_t back_idx; //后端索引
    size_t count; //当前元素数量

    //调整容量辅助函数

    void resize(size_t new_capacity)
    {
        T* new_buffer = new T[new_capacity];
        //重新排列元素
        for (size_t i = 0; i < count; i++)
        {
            new_buffer[i] = buffer[(front_idx + i) % capacity];
        }
        delete[] buffer;
        buffer = new_buffer;
        capacity = new_capacity;
        front_idx = 0; //front_idx指向第一个元素的位置，插入要采取先移动后插入
        back_idx = count; //back_idx指向末尾元素的下一个位置，插入要采取先插入后移动
    }

public:
    Deque(size_t initial_capacity = 10): capacity(initial_capacity), count(0),
                                         front_idx(0), back_idx(0)
    {
        buffer = new T[capacity];
    }

    ~Deque()
    {
        delete[] buffer;
    }

    bool empty() const
    {
        return count == 0;
    }

    size_t size() const
    {
        return count;
    }


    //头插，先移动idx，再进行插入
    //尾插，先插入，再移动idx
    //这样做最终可以避免插入覆盖（采用count=capcity来判断是否满了）
    void push_front(const T& value)
    {
        if (count == capacity)
        {
            resize(capacity * 2); //自动扩容
        }
        front_idx = (front_idx == 0) ? capacity - 1 : front_idx - 1;
        buffer[front_idx] = value;
        count++;
    }

    void push_back(const T& value)
    {
        if (count == capacity)
        {
            resize(capacity * 2);
        }
        buffer[back_idx] = value;
        back_idx = (back_idx + 1) % capacity;
        count++;
    }

    //删除
    void pop_front()
    {
        if (empty())
        {
            throw std::out_of_range("Deque is empty");
        }
        front_idx = (front_idx + 1) % capacity; //移动前端索引
        --count;
    }

    void pop_back()
    {
        if (empty())
        {
            throw std::out_of_range("Deque is empty");
        }
        back_idx = (back_idx == 0) ? capacity - 1 : back_idx - 1; //移动后端索引
        --count;
    }

    //访问元素
    T& front()
    {
        if (empty())
        {
            throw std::out_of_range("Deque is empty");
        }
        return buffer[front_idx];
    }

    const T& front() const
    {
        if (empty())
        {
            throw std::out_of_range("Deque is empty");
        }
        return buffer[front_idx];
    }

    T& back()
    {
        if (empty())
        {
            throw std::out_of_range("Deque is empty");
        }
        size_t last_idx = (back_idx == 0) ? capacity - 1 : back_idx - 1;
        //back_idx指向最后一个元素的下一个位置，所以需要减1，但是如果back_idx为0，则需要回绕到最后一个元素
        return buffer[last_idx]; //返回最后一个元素
    }

    const T& back() const
    {
        if (empty())
        {
            throw std::out_of_range("Deque is empty");
        }
        size_t last_idx = (back_idx == 0) ? capacity - 1 : back_idx - 1;
        return buffer[last_idx];
    }

    //嵌套一个迭代器类
    class Iterator
    {
    private:
        Deque<T>* deque;
        size_t pos; //偏移量

    public:
        using iterator_category = std::bidirectional_iterator_tag; //双向迭代器
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        Iterator(Deque<T>* dq, size_t p): deque(dq),
                                          pos(p)
        {
        }

        reference operator*() const
        {
            size_t real_idx = (deque->front_idx + pos) % deque->capacity;
            return (deque->buffer[real_idx]);
        }

        pointer operator->() const
        {
            size_t real_idx = (deque->front_idx + pos) % deque->capacity;
            return &(deque->buffer[real_idx]);
        }

        //前置递增
        Iterator& operator++()
        {
            pos++;
            return *this;
        }

        //后置递增
        Iterator operator++(int)
        {
            Iterator temp = *this;
            ++pos;
            return temp;
        }

        Iterator& operator--()
        {
            pos--;
            return *this;
        }

        Iterator operator--(int)
        {
            Iterator temp = *this;
            --pos;
            return temp;
        }

        //比较操作符
        bool operator==(const Iterator& other) const
        {
            return (deque == other.deque) && (pos == other.pos);
        }

        bool operator!=(const Iterator& other) const
        {
            return (deque != other.deque) || (pos != other.pos);
        }
    };

    //返回begin和end
    Iterator begin() const
    {
        return Iterator(this, 0);
    }

    Iterator end() const
    {
        return Iterator(this, count);
    }
};


#endif //DEQUE_H
