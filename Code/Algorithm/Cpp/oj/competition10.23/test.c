#include <stdio.h>

int main(void)
{
    long long m = 10 ^ 18;
    printf("%lld\n", m % 998244353);
    return 0;
}