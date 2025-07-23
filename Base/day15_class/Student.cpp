//
// Created by baozi on 2025/7/21.
//

#include "Student.h"

Student::Student(const std::string& name, int age, int id) : name_(name),
    age_(age)
{
}

Student::Student(const Student& other): name_(other.name_), age_(other.age_)
{
    // 拷贝构造函数
    // 这里可以添加其他需要的初始化逻辑
}

void Student::setName(const std::string& name) { name_ = name; }

std::string Student::getName() const { return name_; }

void Student::setAge(int age)
{
    if (age > 0)
        age_ = age;
}

int Student::getAge() const { return age_; }
