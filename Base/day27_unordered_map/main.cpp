#include <iostream>

//unordered_map的模板
//std::unordered_map<KeyType, ValueType, Hash = std::hash<KeyType>,
//KeyEqual = std::equal_to<KeyType>,
//Allocator = std::allocator<std::pair<const KeyType, ValueType>>>

//KeyType:键的类型，需要支持哈希运算和相等比较。
//ValueType:值的类型，可以是任意类型。
//Hash:哈希函数类型，默认为std::hash<KeyType>，可以自定义哈希函数。
//KeyEqual:键比较函数类型，默认为std::equal_to<KeyType>，可以自定义键比较函数。

//Allocator:分配器类型
//默认为std::allocator<std::pair<const KeyType, ValueType>>，可以自定义分配器。


//手写一个unordered_map,
//需要实现一个哈希表，哈希表具有的特性：
//哈希函数：将键映射到表中一个特定的桶（Bucket）或槽（Slot）。
//冲突解决：当两个键映射到同一个桶时，需要有一种方法来处理这种冲突。这里用链地址法
//负载因子：表示表中已存储元素的数量与表大小之间的比率。高负载因子可能导致更多的冲突，需要通过扩容来维持性能。
#include "HashMap.h"

int main()
{
    HashMap<std::string, int> myMap;

    // 插入元素
    myMap.insert("apple", 3);
    myMap.insert("banana", 5);
    myMap.insert("orange", 2);
    myMap.insert("grape", 7);
    myMap.insert("cherry", 4);

    // 使用迭代器遍历元素
    std::cout << "Map contents:\n";
    for (auto it = myMap.begin(); it != myMap.end(); ++it)
    {
        std::cout << it->first << " => " << it->second << "\n";
    }

    // 查找元素
    std::string keyToFind = "banana";
    int* value = myMap.find(keyToFind);
    if (value != nullptr)
    {
        std::cout << "\nFound " << keyToFind << " with value: " << *value <<
            "\n";
    }
    else
    {
        std::cout << "\n" << keyToFind << " not found.\n";
    }

    // 删除元素
    myMap.erase("apple");
    myMap.erase("cherry");

    // 再次遍历
    std::cout << "\nAfter erasing apple and cherry:\n";
    for (auto it = myMap.begin(); it != myMap.end(); ++it)
    {
        std::cout << it->first << " => " << it->second << "\n";
    }

    return 0;
}
