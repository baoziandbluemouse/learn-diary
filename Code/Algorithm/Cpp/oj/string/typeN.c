#include <stdio.h>

int main(void)
{
    long long x;
    long long i = 0;
    long long p = 0;
    long long n = 0;
    scanf("%lld", &x);

    while (x != 0)
    {
        i = x % 10;
        p = p * 10 + i;
        x = x / 10;
    }

    printf("%lld", p);

    return 0;
}