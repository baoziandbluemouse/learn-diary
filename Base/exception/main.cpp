#include <iostream>
#include <stdexcept>

/*
*try 块用于包含可能引发异常的代码。
 throw 用于抛出异常。
 catch 块用于捕获并处理异常。
*/
//计算除法，如果除数为0，则抛出异常。
double divide(double numerator, double denominator)
{
    if (denominator == 0)
    {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
    return numerator / denominator;
}


int main()
{
    {
        double numerator, denominator;
        std::cout << "Enter numerator: ";
        std::cin >> numerator;
        std::cout << "Enter denominator: ";
        std::cin >> denominator;
        try
        {
            double result = divide(numerator, denominator);
            std::cout << "Result: " << result << std::endl;
        }
        catch (std::invalid_argument &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    return 0;
}
