//
// Created by baozi on 2025/8/8.
//

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <memory>

class ResourceManager
{
public:
    ResourceManager();
    ResourceManager(int x);
    //析构函数靠智能指针自动管理,不显示定义

    //删除拷贝构造和拷贝赋值
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;
    //允许移动语义
    ResourceManager(ResourceManager&& other) noexcept;
    ResourceManager& operator=(ResourceManager&& other) noexcept;

    //其他成员函数
    int getValue() const; //返回管理的整数值

    void setValue(int x); //设置管理的整数值
private:
    std::unique_ptr<int> resource; // 管理一个整数类型的资源
};


#endif //RESOURCEMANAGER_H
