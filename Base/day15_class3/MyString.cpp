//
// Created by baozi on 2025/7/21.
//

#include "MyString.h"
#include<iostream>
#include<cstring>

MyString::MyString(): _str(nullptr)
{
}

MyString::MyString(const char* str)
{
    if (str)
    {
        _str = new char[strlen(str) + 1];
        strcpy(_str, str);
    }
    else _str = nullptr;
}

MyString::MyString(const MyString& other)
{
    if (other._str)
    {
        _str = new char[strlen(other._str) + 1];
        strcpy(_str, other._str);
    }
    else _str = nullptr;
}

MyString::~MyString()
{
    if (_str) delete [] _str;
    _str = nullptr;
}

MyString& MyString::operator=(const MyString& other)
{
    if (this != &other)
    {
        delete [] _str;
        if (other._str)
        {
            _str = new char[strlen(other._str) + 1];
            strcpy(_str, other._str);
        }
        else _str = nullptr;
    }
    return *this;
}

bool MyString::operator==(const MyString& other)
{
    if (_str == nullptr && other._str == nullptr)return true;
    if (_str == nullptr || other._str == nullptr)return false;
    return strcmp(_str, other._str) == 0;
}

std::ostream& operator<<(std::ostream& os, const MyString& other)
{
    if (other._str) os << other._str;
    return os;
}
