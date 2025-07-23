//
// Created by baozi on 2025/7/21.
//

#ifndef MYSTRING_H
#define MYSTRING_H
#include<cstring>
#include <iosfwd>


class MyString
{
private:
    char* _str; //c风格字符串
public:
    //默认构造函数
    MyString();
    //有参构造
    MyString(const char* str);
    //拷贝构造
    MyString(const MyString& other);
    //赋值运算符重载
    MyString& operator=(const MyString& other);
    //比较运算符重载
    bool operator==(const MyString& other);
    //输出运算符重载
    friend std::ostream& operator<<(std::ostream& os, const MyString& other);
    //析构函数
    ~MyString();
};


#endif //MYSTRING_H
