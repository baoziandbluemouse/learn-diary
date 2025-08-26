//
// Created by baozi on 2025/8/12.
//

#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <stack>
#include <utility>
#include <exception>

template <typename Key, typename T>
struct TreeNode
{
    std::pair<Key, T> data;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    TreeNode(Key key, T value, TreeNode* p = nullptr): data({key, value}),
        left(nullptr), right(nullptr), parent(p)
    {
    }
};

template <typename Key, typename T>
class Map
{
public:
    Map(): root(nullptr)
    {
    }

    ~Map()
    {
        clear(root);
    }

    //禁止拷贝构造和赋值
    Map(const Map&) = delete;
    Map& operator=(const Map&) = delete;

    void clear()
    {
        //主动调用清理函数
        clear(root);
        root = nullptr;
    }

    //插入或更新键值对
    void insert(const Key& key, const T& value)
    {
        if (root == nullptr)
        {
            root = new TreeNode<Key, T>(key, value);
            return;
        }
        TreeNode<Key, T>* current = root;
        TreeNode<Key, T>* parent = nullptr;

        //寻找插入位置的父节点
        while (current != nullptr)
        {
            parent = current;
            if (key < current->data.first)
            {
                current = current->left;
            }
            else if (key > current->data.first)
            {
                current = current->right;
            }
            else
            {
                //键已存在，更新值
                current->data.second = value;
                return;
            }
        }
        //创建新节点
        auto newNode = new TreeNode<Key, T>(key, value, parent);
        if (key < parent->data.first)
        {
            parent->left = newNode;
        }
        else
        {
            parent->right = newNode;
        }
    }

    //查找元素，返回指定节点的指针
    TreeNode<Key, T>* find(const Key& key) const
    {
        auto current = root;
        //遍历树寻找键
        while (current != nullptr)
        {
            if (key < current->data.first)
            {
                current = current->left;
            }
            else if (key > current->data.first)
            {
                current = current->right;
            }
            else
            {
                return current;
            }
        }
        return nullptr;
    }

    //删除指定键的节点
    void erase(const Key& key)
    {
        auto node = find(key);
        if (node == nullptr) return; //键不存在

        //如果节点有两个子节点,那么找到其中序后继节点，用后继节点的值替换当前节点的值，然后删除后继节点
        if (node->left != nullptr && node->right != nullptr)
        {
            auto temp = minimum(node->right);
            node->data = temp->data; //用后继节点的值替换当前
            node = temp; //指向后继节点，后续删除
        }

        //处理节点有0或1个子节点的情况,如果节点有两个子节点，那么这里处理的是后继节点的右子树
        auto child = (node->left) ? node->left : node->right;
        if (child != nullptr)
        {
            child->parent = node->parent;
        }
        if (node->parent == nullptr)
        {
            root = child; //根节点被删了，child成为新的根节点
        }
        else if (node == node->parent->left)
        {
            node->parent->left = child;
        }
        else
        {
            node->parent->right = child;
        }

        delete node;
    }

    //迭代器
    class Iterator
    {
    public:
        Iterator(TreeNode<Key, T>* node = nullptr): current(node)
        {
        }

        std::pair<Key, T>& operator*() const
        {
            return current->data;
        }

        std::pair<Key, T>* operator->() const
        {
            return &(current->data);
        }

        //前置++
        Iterator& operator++()
        {
            current = successor(current);
            return *this;
        }

        //后置++
        Iterator operator++(int)
        {
            Iterator temp = *this;
            current = successor(current);
            return temp;
        }

        bool operator==(const Iterator& other) const
        {
            return current == other.current;
        }

        bool operator!=(const Iterator& other) const
        {
            return current != other.current;
        }

    private:
        TreeNode<Key, T>* current;

        //找到最小的节点
        TreeNode<Key, T>* minimum(TreeNode<Key, T>* node) const
        {
            if (node == nullptr) return nullptr;
            while (node->left != nullptr)
            {
                node = node->left;
            }
            return node;
        }

        //找到中序后继节点
        TreeNode<Key, T>* successor(TreeNode<Key, T>* node) const
        {
            if (node->right != nullptr)
            {
                return minimum(node->right);
            }
            auto p = node->parent;
            while (p != nullptr && node == p->right)
            {
                node = p;
                p = p->parent;
            }
            return p;
        }
    };

    Iterator begin() const
    {
        return Iterator(minimum(root));
    }

    Iterator end() const
    {
        return Iterator(nullptr);
    }

private:
    TreeNode<Key, T>* root;

    void clear(TreeNode<Key, T>* node)
    {
        if (node != nullptr)
        {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    //找到最小的节点
    TreeNode<Key, T>* minimum(TreeNode<Key, T>* node) const
    {
        if (node == nullptr) return nullptr;
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    //找到最大的节点
    TreeNode<Key, T>* maximum(TreeNode<Key, T>* node) const
    {
        if (node == nullptr) return nullptr;
        while (node->right != nullptr)
        {
            node = node->right;
        }
        return node;
    }
};


#endif //MAP_H
