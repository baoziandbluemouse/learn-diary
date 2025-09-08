#include <stdio.h>

int Fibonacci(int n);
int main(void)
{
    int n;
    int ret = 0;
    while (scanf("%d", &n) != EOF)
    {
        ret = Fibonacci(n);
        printf("%d\n", ret);
    }
    return 0;
}

int Fibonacci(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}