#include <iostream>

class Data
{
public:
    Data() { std::cout << "Data default constructor\n"; }
    Data(int v) : value(v) { std::cout << "Data(int) constructor\n"; }
    int value = 0;
};

class Example
{
public:
    Example()
    {
    } // 没有在初始化列表中初始化data_
private:
    Data data_;
};

int main()
{
    Example ex;
    return 0;
}
