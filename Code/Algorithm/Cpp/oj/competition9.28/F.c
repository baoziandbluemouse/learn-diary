#include <stdio.h>
int main(void)
{
    long long a, b, x, y;
    scanf("%lld%lld%lld%lld", &x, &y, &a, &b);
    long long i, j, q, p;
    int days = 1;

    i = x - 1;
    j = y + 1;

    while (1)
    {
        i = i + a;
        j = j - b;

        if (i >= j)
        {
            printf("%d\n", days);
            return 0;
        }
        else
        {
            days++;
        }
    }
}