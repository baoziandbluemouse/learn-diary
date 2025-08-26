//
// Created by baozi on 2025/8/13.
//

#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //用于std::max
#include <functional> //用于std::function

template <typename Keytype, typename Valuetype>
struct AVLNode
{
    Keytype key;
    Valuetype value;
    AVLNode* left;
    AVLNode* right;
    int height; // 节点高度,用于AVL树平衡
    AVLNode(const Keytype& k, const Valuetype& v): key(k), value(v),
                                                   left(nullptr),
                                                   right(nullptr), height(1)
    {
    }
};


template <typename Keytype, typename ValueType>
class Map
{
public:
    Map(): root(nullptr)
    {
    }

    //插入或更新键值对
    void put(const Keytype& k, const ValueType& v)
    {
        root = insertNode(root, k, v);
    }

    //根据键获取值的指针，找不到返回nullptr
    ValueType* get(const Keytype& k)
    {
        return searchNode(root, k);
    }

    //删除键值对
    void remove(const Keytype& k)
    {
        root = eraseNode(root, k);
    }

    //中序遍历，返回所有键值对
    std::vector<std::pair<Keytype, ValueType>> inorder() const
    {
        std::vector<std::pair<Keytype, ValueType>> result;
        inorderhelp(root, result);
        return result;
    }

    //析构函数，释放所有节点
    ~Map()
    {
        std::function<void(AVLNode<Keytype, ValueType>*)> destroy = [&](
            AVLNode<Keytype, ValueType>* node)
        {
            if (node != nullptr)
            {
                destroy(node->left);
                destroy(node->right);
                delete node;
            }
        };
        destroy(root);
    }

private:
    AVLNode<Keytype, ValueType>* root;

    int gethegiht(AVLNode<Keytype, ValueType>* node)
    {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int getBalance(AVLNode<Keytype, ValueType>* node)
    {
        // 平衡因子 = 左子树高度 - 右子树高度
        if (node == nullptr)
            return 0;
        return gethegiht(node->left) - gethegiht(node->right);
    }

    //处理失衡的基本操作是左旋和右旋，下面四种情况都是采用左旋或右旋解决的
    //左左情况：给根节点的左孩子的左子树插入一个节点，导致失衡 ---->对根节点右旋
    //右右情况：给根节点的右孩子的右子树插入一个节点，导致失衡 ---->对根节点左旋
    //左右情况：给根节点的左孩子的右子树插入一个节点，导致失衡 ---->对左孩子左旋+对根节点右旋
    //右左情况：给根节点的右孩子的左子树插入一个节点，导致失衡 ---->对右孩子右旋+对根节点左旋

    AVLNode<Keytype, ValueType>* rightRotate(AVLNode<Keytype, ValueType>* y)
    {
        // 右旋转处理左子树过高的情况
        // x是要成为根的节点，y是这个不平衡的树的根节点
        // 以x为根，y转到右子树去，如果x有右子树，则将其转到y的左子树
        AVLNode<Keytype, ValueType>* x = y->left;
        AVLNode<Keytype, ValueType>* T2 = x->right;

        // 进行旋转
        x->right = y;
        y->left = T2;

        // 更新高度
        // 旋转过后，x的右子树变为y，此时想要更新x的高度，必须先得出y的高度
        y->height = std::max(gethegiht(y->left), gethegiht(y->right)) + 1;
        x->height = std::max(gethegiht(x->left), gethegiht(x->right)) + 1;

        return x; // 返回新的根节点
    }

    AVLNode<Keytype, ValueType>* leftRotate(AVLNode<Keytype, ValueType>* x)
    {
        // 左旋转处理右子树过高的情况
        // y是要成为根的节点，x是这个不平衡的树的根节点
        // 以y为根，x转到左子树去，如果y有左子树，则将其转到x的右子树
        AVLNode<Keytype, ValueType>* y = x->right;
        AVLNode<Keytype, ValueType>* T2 = y->left;

        // 进行旋转
        y->left = x;
        x->right = T2;

        // 更新高度
        // 旋转过后，y的左子树变为x，此时想要更新y的高度，必须先得出x的高度
        x->height = std::max(gethegiht(x->left), gethegiht(x->right)) + 1;
        y->height = std::max(gethegiht(y->left), gethegiht(y->right)) + 1;

        return y; // 返回新的根节点
    }

    // 获取最小值节点，用于删除操作时找到中序后继节点
    AVLNode<Keytype, ValueType>* getMinvalueNode(
        AVLNode<Keytype, ValueType>* node)
    {
        // 获取最小值节点
        AVLNode<Keytype, ValueType>* current = node;
        while (current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    //中序遍历辅助函数
    void inorderhelp(AVLNode<Keytype, ValueType>* node,
                     std::vector<std::pair<Keytype, ValueType>>& res) const
    {
        if (node != nullptr)
        {
            inorderhelp(node->left, res);
            res.emplace_back(node->key, node->value);
            inorderhelp(node->right, res);
        }
    }

    AVLNode<Keytype, ValueType>* insertNode(AVLNode<Keytype, ValueType>* node,
                                            const Keytype& key,
                                            const ValueType& value)
    {
        //1.执行标准的BST插入
        if (node == nullptr)return new AVLNode<Keytype, ValueType>(key, value);
        // 新节点的创建在此处返回

        if (key < node->key)
        {
            node->left = insertNode(node->left, key, value);
        }
        else if (key > node->key)
        {
            node->right = insertNode(node->right, key, value);
        }
        else
        {
            // 如果键已经存在，更新值
            node->value = value;
            return node;
        }

        //在新节点插入结束后，剩下的那些递归首先更新高度，然后开始检查是否失衡，然后据此返回

        //2.更新当前节点的高度
        node->height = std::max(gethegiht(node->left), gethegiht(node->right)) +
            1;

        //3.获取平衡因子
        int balance = getBalance(node);

        //4.根据平衡因子进行旋转
        // 左左情况
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // 右右情况
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // 左右情况
        if (balance > 1 && key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // 右左情况
        if (balance < -1 && key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        // 没有失衡，直接返回当前节点
        return node;
    }

    ValueType* searchNode(AVLNode<Keytype, ValueType>* node, const Keytype& key)
    {
        if (node == nullptr)return nullptr;
        if (key == node->key)
        {
            return &(node->value);
        }
        else if (key < node->key)
        {
            return searchNode(node->left, key);
        }
        else if (key > node->key)
        {
            return searchNode(node->right, key);
        }
    }

    //删除操作分为三种情况：删除节点是叶子节点、有一个子节点或有两个子节点。
    //删除后，通过旋转保持树的平衡。
    AVLNode<Keytype, ValueType>* eraseNode(AVLNode<Keytype, ValueType>* node,
                                           const Keytype& key)
    {
        //1.执行标准的BST删除
        if (node == nullptr)
            return node; // 如果节点为空，直接返回
        if (key < node->key)
        {
            node->left = eraseNode(node->left, key);
        }
        else if (key > node->key)
        {
            node->right = eraseNode(node->right, key);
        }
        else
        {
            //首先检查当前节点有几个子节点
            if (node->left == nullptr || node->right == nullptr)
            {
                auto temp = node->left ? node->left : node->right;
                //没有子节点
                if (temp == nullptr)
                {
                    temp = node;
                    node = nullptr; // 删除当前节点
                }
                else
                {
                    // 有一个子节点
                    *node = *temp; // 将当前节点替换为子节点
                }
                delete temp;
            }
            else
            {
                //有两个子节点，找到中序后继节点，用它替换当前节点
                auto temp = getMinvalueNode(node->right);
                // 复制资源
                node->key = temp->key;
                node->value = temp->value;
                // 删除中序后继节点
                node->right = eraseNode(node->right, temp->key);
            }
        }

        //2.删除结束，开始更新高度，以及进行失衡检查

        if (node == nullptr)
            return node; // 如果节点被删除，直接返回

        node->height = 1 + std::max(gethegiht(node->left),
                                    gethegiht(node->right));

        //3.获取平衡因子
        int balance = getBalance(node);

        //4.失衡检查，由于是删除操作，我们只能通过获取根节点孩子的平衡因子来区分

        //左左情况，根节点左孩子的平衡因子>=0
        if (balance > 1 && getBalance(node->left) >= 0)
            return rightRotate(node);

        //左右情况，根节点左孩子的平衡因子<0
        if (balance > 1 && getBalance(node->left) < 0)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        //右右情况，根节点右孩子的平衡因子 <=0
        if (balance < -1 && getBalance(node->right) <= 0)
            return leftRotate(node);

        //右左情况，根节点右孩子的平衡因子 >0
        if (balance < -1 && getBalance(node->right) > 0)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        // 没有失衡，直接返回当前节点
        return node;
    }
};


#endif //MAP_H
