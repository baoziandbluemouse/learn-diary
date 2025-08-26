//
// Created by baozi on 2025/7/26.
//

#ifndef BASE_H
#define BASE_H


class Base
{
public:
    virtual void show() const { std::cout << "Base show" << std::endl; }

    virtual ~Base()
    {
    }
};

class Derived : public Base
{
public:
    void show() const override { std::cout << "Derived show" << std::endl; }
};

#endif //BASE_H
