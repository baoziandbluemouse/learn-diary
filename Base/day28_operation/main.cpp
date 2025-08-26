#include <iostream>


class Complex
{
public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i)
    {
    }

    Complex operator+(const Complex& b) const
    {
        return Complex(real + b.real, imag + b.imag);
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& b);

private:
    double real;
    double imag;
};

std::ostream& operator<<(std::ostream& os, const Complex& b)
{
    os << "( " << b.real;
    if (b.imag >= 0)
    {
        os << " + " << b.imag << "i )";
    }
    else
    {
        os << " - " << -b.imag << "i )";
    }
    return os;
}

int main()
{
    Complex x = Complex(2.0, 3.0);
    Complex y = Complex(1.0, 4.0);
    Complex z = x + y;
    std::cout << "Result of addition: " << z << std::endl;
    return 0;
}
