//
// Created by baozi on 2025/8/8.
//

#include "ResourceManager.h"

#include <iostream>

ResourceManager::ResourceManager(): resource(std::make_unique<int>(0))
{
}


ResourceManager::ResourceManager(int x): resource(std::make_unique<int>(x))
{
    std::cout << "ResourceManager::ResourceManager(int x)" << std::endl;
}

ResourceManager::ResourceManager(ResourceManager&& other) noexcept
{
    if (this != &other)
    {
        resource = std::move(other.resource);
    }
    other.resource = nullptr;
    std::cout << "ResourceManager::ResourceManager(ResourceManager&& other)" <<
        std::endl;
}

ResourceManager& ResourceManager::operator=(ResourceManager&& other) noexcept
{
    if (this != &other)
    {
        resource = std::move(other.resource);
    }
    other.resource = nullptr;
    std::cout << "ResourceManager::operator=(ResourceManager&& other)" <<
        std::endl;
    return *this;
}

int ResourceManager::getValue() const
{
    if (resource)
    {
        // 如果资源存在，返回其值
        return *resource;
    }
    return 0; // 如果资源不存在，返回默认值
}

void ResourceManager::setValue(int x)
{
    if (resource)
    {
        // 如果资源已存在，直接修改值
        *resource = x;
    }
}
