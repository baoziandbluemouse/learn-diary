#include <iostream>
#include <vector>

//运用成员函数进行运算符重载
class Complex
{
public:
    double real, imag;

    Complex operator+(const Complex& c1)
    {
        Complex temp;
        temp.real = real + c1.real;
        temp.imag = imag + c1.imag;
        return temp;
    }
};

//运用友元函数进行运算符重载
class Complex2
{
public:
    double real, imag;
    friend Complex2 operator+(const Complex2& c1, const Complex2& c2);
};

Complex2 operator+(const Complex2& c1, const Complex2& c2)
{
    Complex2 temp;
    temp.real = c1.real + c2.real;
    temp.imag = c1.imag + c2.imag;
    return temp;
}

void square(int* ptr)
{
    *ptr = (*ptr) * (*ptr);
}

int range_sum(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    int sum = 0;
    for (auto it = begin; it != end; it++)
    {
        sum += (*it);
    }
    return sum;
}


int main()
{
    //小技巧异或交换
    int x = 15;
    int y = 27;

    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;

    // 交换操作
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;

    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;
    //无需第三个变量

    //平方函数
    int p = 5;
    std::cout << "Before square: p = " << p << std::endl;
    square(&p);
    std::cout << "After square: p = " << p << std::endl;
    //range求和
    std::vector<int> vec = {100, 2, 3};
    int sum = range_sum(vec.begin(), vec.end());
    std::cout << "vec sum = " << sum << std::endl;
    return 0;
}
