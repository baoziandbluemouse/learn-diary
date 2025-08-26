//
// Created by baozi on 2025/8/9.
//

#ifndef MYLIST_H
#define MYLIST_H
#include <cstddef>
#include <iostream>
//实现一个简单的链表类
//实现功能：
//链表基础功能，模板类，一些常用的函数，实现一个简单的迭代器,迭代器是MyList的内部类
//支持一些泛型算法


template <typename T>
struct Node
{
    T data;
    Node* next;
    Node* prev;

    Node(const T& value = T()): data(value), next(nullptr), prev(nullptr)
    {
    }
};

template <typename T>
class MyList;

template <typename T>
class Iterator
{
public:
    using self_type = Iterator<T>;
    using value_type = T;
    using reference = T&;
    using pointer = T*;
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = std::ptrdiff_t;

    Iterator(Node<T>* ptr = nullptr): node_ptr(ptr)
    {
    }

    reference operator*() const
    {
        return node_ptr->data;
    }

    pointer operator->() const
    {
        return &(node_ptr->data);
    }

    self_type& operator++()
    {
        //++it
        if (node_ptr)
        {
            node_ptr = node_ptr->next;
        }
        return *this;
    }

    self_type operator++(int)
    {
        //it++
        self_type tmp = *this;
        ++(*this); //*this是迭代器自己，调用了前置++
        return tmp;
    }

    self_type& operator--()
    {
        //--it
        if (node_ptr)
        {
            node_ptr = node_ptr->prev;
        }
        return *this;
    }

    self_type operator--(int)
    {
        //it--
        self_type tmp = *this;
        --(*this); //*this是迭代器自己，调用了前置--
        return tmp;
    }

    bool operator==(const self_type& ohter) const
    {
        return node_ptr == ohter.node_ptr;
    }

    bool operator!=(const self_type& ohter) const
    {
        return node_ptr != ohter.node_ptr;
    }

private:
    Node<T>* node_ptr;

    friend class MyList<T>;
};

template <typename T>
class MyList
{
public:
    using iterator = Iterator<T>;
    using const_iterator = Iterator<const T>;

    //构造函数
    MyList()
    {
        head = new Node<T>();
        tail = new Node<T>();
        head->next = tail;
        tail->prev = head;
    }

    ~MyList()
    {
        clear();
        delete head;
        delete tail;
    }

    //清空list
    void clear()
    {
        Node<T>* current = head->next;
        while (current != tail)
        {
            Node<T>* tmp = current;
            current = current->next;
            delete tmp;
        }
        head->next = tail;
        tail->prev = head;
    }

    //禁止拷贝构造和赋值
    MyList(const MyList&) = delete;
    MyList& operator=(const MyList&) = delete;

    //插入元素到迭代器位置之前

    iterator insert(iterator pos, const T& value)
    {
        Node<T>* new_node = new Node<T>(value);
        auto current = pos.node_ptr;
        auto prev_node = current->prev;
        //新节点插入到pos之前，prev之后
        new_node->next = current;
        new_node->prev = prev_node;

        prev_node->next = new_node;
        current->prev = new_node;
        return iterator(new_node);
    }

    //删除迭代器指向的元素

    iterator erase(iterator pos)
    {
        auto current = pos.node_ptr;
        if (current == head || current == tail)
        {
            return iterator(tail); //不能删除头尾节点
        }
        auto next_node = current->next;
        auto prev_node = current->prev;
        //将前后节点连接起来
        prev_node->next = next_node;
        next_node->prev = prev_node;

        delete current;
        return iterator(next_node);
    }

    //返回头尾迭代器
    iterator begin()
    {
        return iterator(head->next);
    }

    iterator end()
    {
        return iterator(tail);
    }

    void push_front(const T& value)
    {
        insert(begin(), value);
    }

    void push_back(const T& value)
    {
        insert(end(), value);
    }

    //判空

    bool empty()
    {
        return head->next == tail;
    }

    //获取头，尾
    T& front()
    {
        if (!empty())
        {
            return head->next->data;
        }
    }

    T& back()
    {
        if (!empty())
        {
            return tail->prev->data;
        }
    }

    //头删，尾删

    void pop_front()
    {
        if (!empty())
        {
            erase(begin());
        }
    }

    void pop_back()
    {
        if (!empty())
        {
            erase(--end());
        }
    }

    // 获取链表大小（O(n)复杂度）
    size_t size() const
    {
        size_t count = 0;
        for (auto it = begin(); it != end(); ++it)
        {
            ++count;
        }
        return count;
    }

    // 打印链表（辅助函数）
    void print() const
    {
        Node<T>* current = head->next;
        while (current != tail)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

private:
    //头尾指针
    Node<T>* head;
    Node<T>* tail;
};


#endif //MYLIST_H
