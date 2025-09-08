#include <stdio.h>
int max(int x, int y, int z);

int main(void)
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    int m = max(a, b, c);
    int n = max(a + b, b, c);
    int k = max(a, b, b + c);

    printf("%.3lf\n", (double)m / (n * k));
    return 0;
}

int max(int x, int y, int z)
{
    int max = -1;
    if (x > max)
    {
        max = x;
    }
    if (y > max)
    {
        max = y;
    }
    if (z > max)
    {
        max = z;
    }
    return max;
}