//
// Created by baozi on 2025/8/16.
//

#ifndef HASHMAP_H
#define HASHMAP_H
#include <vector>
#include <list>
#include <utility>//for std::pair
#include <functional>// for std::hash
#include <iterator>// for iterator_traits
#include <stdexcept>//for exceptions

//HashNode
//HashNode 用于存储键值对及相关的指针，以构建链表。
//每个 HashNode 包含键、值和指向下一个节点的指针。
template <typename Key, typename T>
struct HashNode
{
    std::pair<const Key, T> data;
    HashNode* next;

    HashNode(const Key& key, const T& value): data(std::make_pair(key, value)),
                                              next(nullptr)
    {
    }
};

//MyHashMap 是我们自定义的哈希表实现，支持基本的 Map 操作和迭代器功能。
//它使用一个向量（std::vector）来存储桶，每个桶是一个链表，用于处理冲突。


template <typename Key, typename T, typename Hash = std::hash<Key>>
class HashMap
{
public:
    //迭代器类前向声明
    class Iterator;
    using key_type = Key;
    using mapped_type = T;
    using value_type = std::pair<const Key, T>;
    using size_type = std::size_t;

    //构造及析构
    HashMap(size_type initial_capacity = 16, double max_load_factor = 0.75);
    ~HashMap();

    // 禁止拷贝构造和赋值
    HashMap(const HashMap&) = delete;
    HashMap& operator=(const HashMap&) = delete;


    //基本操作
    // 基本操作
    void insert(const Key& key, const T& value);
    T* find(const Key& key);
    const T* find(const Key& key) const;
    bool erase(const Key& key);
    size_type size() const;
    bool empty() const;
    void clear();

    // 迭代器操作
    Iterator begin();
    Iterator end();

    //内嵌迭代器
    class Iterator
    {
    public:
        //别名
        using iterator_category = std::forward_iterator_tag; //前向迭代器
        using value_type = std::pair<const Key, T>;
        using difference_type = std::ptrdiff_t;
        using pointer = value_type*;
        using reference = value_type&;
        // 构造函数
        Iterator(HashMap* map, size_type bucket_index, HashNode<Key, T>* node);

        // 解引用操作符
        reference operator*() const;
        pointer operator->() const;

        // 递增操作符
        Iterator& operator++();
        Iterator operator++(int);

        // 比较操作符
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;

    private:
        HashMap* map_;
        size_type bucket_index_;
        HashNode<Key, T>* current_node_;
        //移动到下一个有效节点
        void advance();
    };

private:
    std::vector<HashNode<Key, T>*> buckets_;
    size_type bucket_count_;
    size_type element_count_;
    double max_load_factor_;
    Hash hash_func_;
    //辅助函数
    void rehash();
};


//构造函数
template <typename Key, typename T, typename Hash>
HashMap<Key, T, Hash>::HashMap(size_type initial_capacity,
                               double max_load_factor):
    bucket_count_(initial_capacity), element_count_(0),
    max_load_factor_(max_load_factor), hash_func_(Hash())
{
    buckets_.resize(bucket_count_, nullptr);
}


//析构函数
template <typename Key, typename T, typename Hash>
HashMap<Key, T, Hash>::~HashMap()
{
    clear();
}

//插入键值对
template <typename Key, typename T, typename Hash>
void HashMap<Key, T, Hash>::insert(const Key& key, const T& value)
{
    size_type hash_value = hash_func_(key);
    size_type bucket_index = hash_value % bucket_count_;
    HashNode<Key, T>* node = buckets_[bucket_index];
    while (node != nullptr)
    {
        if (node->data.first == key)
        {
            node->data.second = value; //如果键已存在，更新值
            return;
        }
        node = node->next;
    }

    // 如果键不存在，创建一个新的 HashNode 并插入到链表的头部
    HashNode<Key, T>* new_node = new HashNode<Key, T>(key, value);
    new_node->next = buckets_[bucket_index]; //新节点的next指向当前桶的头节点
    buckets_[bucket_index] = new_node; //将新节点设置为桶的头节点
    ++element_count_;

    // 检查负载因子，如果超过最大负载因子，则重新哈希
    double load_factor = static_cast<double>(element_count_) / bucket_count_;
    if (load_factor > max_load_factor_)
    {
        rehash();
    }
}

//查找指定键的元素
template <typename Key, typename T, typename Hash>
T* HashMap<Key, T, Hash>::find(const Key& key)
{
    size_type hash_value = hash_func_(key);
    size_type bucket_index = hash_value % bucket_count_;
    HashNode<Key, T>* node = buckets_[bucket_index];
    while (node != nullptr)
    {
        if (node->data.first == key)
        {
            return &(node->data.second);
        }
        node = node->next;
    }
    return nullptr;
}

//查找指定键的元素(常量版)
template <typename Key, typename T, typename Hash>
const T* HashMap<Key, T, Hash>::find(const Key& key) const
{
    size_type hash_value = hash_func_(key);
    size_type bucket_index = hash_value % bucket_count_;
    HashNode<Key, T>* node = buckets_[bucket_index];
    while (node != nullptr)
    {
        if (node->data.first == key)
        {
            return &(node->data.second);
        }
        node = node->next;
    }
    return nullptr;
}

//删除指定键的元素
template <typename Key, typename T, typename Hash>
bool HashMap<Key, T, Hash>::erase(const Key& key)
{
    size_type hash_value = hash_func_(key);
    size_type bucket_index = hash_value % bucket_count_;
    HashNode<Key, T>* node = buckets_[bucket_index];
    HashNode<Key, T>* prev_node = nullptr;
    while (node != nullptr)
    {
        if (node->data.first == key)
        {
            // 找到要删除的节点，并且这个节点不是桶的头节点
            if (prev_node != nullptr)
            {
                prev_node->next = node->next; //将前一个节点的next指向当前节点的下一个节点
            }
            else
            {
                buckets_[bucket_index] = node->next; //如果是头节点，更新桶的头节点
            }
            delete node; //释放当前节点的内存
            --element_count_;
            return true; //返回删除成功
        }
        prev_node = node; //记录前一个节点
        node = node->next; //移动到下一个节点
    }
    return false; //如果没有找到要删除的节点，返回false
}

//返回哈希表中元素的数量
template <typename Key, typename T, typename Hash>
typename HashMap<Key, T, Hash>::size_type HashMap<Key, T, Hash>::size() const
{
    return element_count_;
}

//检查哈希表是否为空
template <typename Key, typename T, typename Hash>
bool HashMap<Key, T, Hash>::empty() const
{
    return element_count_ == 0;
}

//清空哈希表
template <typename Key, typename T, typename Hash>
void HashMap<Key, T, Hash>::clear()
{
    for (size_type i = 0; i < bucket_count_; ++i)
    {
        auto cur_node = buckets_[i];
        while (cur_node != nullptr)
        {
            auto temp = cur_node;
            cur_node = cur_node->next;
            delete temp;
        }
        buckets_[i] = nullptr;
    }
    element_count_ = 0;
}

//begin()和end()方法返回迭代器
template <typename Key, typename T, typename Hash>
typename HashMap<Key, T, Hash>::Iterator HashMap<Key, T, Hash>::begin()
{
    for (size_type i = 0; i < bucket_count_; ++i)
    {
        if (buckets_[i] != nullptr)
        {
            return Iterator(this, i, buckets_[i]);
        }
    }
    // 如果没有找到有效的节点，返回end迭代器
    return end();
}

template <typename Key, typename T, typename Hash>
typename HashMap<Key, T, Hash>::Iterator HashMap<Key, T, Hash>::end()
{
    return Iterator(this, bucket_count_, nullptr); //返回一个指向末尾的迭代器
}

//迭代器的实现
//迭代器的构造函数
template <typename Key, typename T, typename Hash>
HashMap<Key, T, Hash>::Iterator::Iterator(HashMap* map, size_type bucket_index,
                                          HashNode<Key, T>* node): map_(map),
    bucket_index_(bucket_index),
    current_node_(node)
{
}

//迭代器的解引用操作符
template <typename Key, typename T, typename Hash>
typename HashMap<Key, T, Hash>::Iterator::reference HashMap<Key, T, Hash>::
Iterator::operator*() const
{
    if (current_node_ != nullptr)
    {
        return current_node_->data; //返回当前节点的数据
    }
    throw std::out_of_range("Dereferencing end iterator");
}

//迭代器的箭头操作符
template <typename Key, typename T, typename Hash>
typename HashMap<Key, T, Hash>::Iterator::pointer HashMap<Key, T, Hash>::
Iterator::operator->() const
{
    if (current_node_ != nullptr)
    {
        return &(current_node_->data); //返回当前节点数据的地址
    }
    throw std::out_of_range("Dereferencing end iterator");
}

//迭代器的递增操作符
template <typename Key, typename T, typename Hash>
typename HashMap<Key, T, Hash>::Iterator& HashMap<Key, T, Hash>::Iterator::
operator++()
{
    advance();
    return *this; //返回自身的引用
}

//递增操作符的后缀版本
template <typename Key, typename T, typename Hash>
typename HashMap<Key, T, Hash>::Iterator HashMap<Key, T, Hash>::Iterator::
operator++(int)
{
    auto tmp = *this;
    advance();
    return tmp; //返回递增前的迭代器
}

//迭代器的比较操作符(等于)
template <typename Key, typename T, typename Hash>
bool HashMap<Key, T, Hash>::Iterator::operator==(const Iterator& other) const
{
    return map_ == other.map_ && bucket_index_ == other.bucket_index_ &&
        current_node_ == other.current_node_;
}

//迭代器的比较操作符(不等于)
template <typename Key, typename T, typename Hash>
bool HashMap<Key, T, Hash>::Iterator::operator!=(const Iterator& other) const
{
    return !(*this == other); //使用等于操作符的结果取反
}

//辅助函数：移动到下一个有效节点，用于迭代器的递增操作
template <typename Key, typename T, typename Hash>
void HashMap<Key, T, Hash>::Iterator::advance()
{
    if (current_node_ != nullptr)
    {
        current_node_ = current_node_->next;
    }
    //如果当前节点为空，移动到下一个桶
    while (current_node_ == nullptr)
    {
        if (bucket_index_ + 1 < map_->bucket_count_)
        {
            ++bucket_index_;
            current_node_ = map_->buckets_[bucket_index_];
        }
        else if (bucket_index_ + 1 == map_->bucket_count_)
        {
            ++bucket_index_;
            break;
        }
    }
}

//辅助函数，用于动态扩容
template <typename Key, typename T, typename Hash>
void HashMap<Key, T, Hash>::rehash()
{
    size_type new_bucket_count = bucket_count_ * 2;
    std::vector<HashNode<Key, T>*> new_buckets(new_bucket_count, nullptr);
    //重新分配所有元素
    for (size_type i = 0; i < bucket_count_; ++i)
    {
        HashNode<Key, T>* node = buckets_[i];
        while (node != nullptr)
        {
            HashNode<Key, T>* next_node = node->next;
            size_type new_index = hash_func_(node->data.first) %
                new_bucket_count;

            // 将节点插入到新的桶中
            node->next = new_buckets[new_index];
            new_buckets[new_index] = node;

            node = next_node;
        }
    }

    //替换旧桶
    buckets_ = new_buckets;
    bucket_count_ = new_bucket_count;
}
#endif //HASHMAP_H
