//
// Created by baozi on 2025/7/21.
//

#ifndef STUDENT_H
#define STUDENT_H


#include <string>

class Student
{
public:
    // 公有构造函数
    Student(const std::string& name, int age,int id);
    Student(const Student& other);
    // 公有成员函数
    void setName(const std::string& name);
    std::string getName() const;

    void setAge(int age);
    int getAge() const;

private:
    // 私有成员变量
    std::string name_;
    int age_;
};


#endif //STUDENT_H
