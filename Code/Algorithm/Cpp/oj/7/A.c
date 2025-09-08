#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int n, l, r;
    scanf("%d%d%d", &n, &l, &r);

    int k = 0;
    bool flag = false;
    int max = -1;

    if (l % n == n - 1)
    {
        max = l % n;
        flag = true;
    }
    if (r % n == n - 1)
    {
        max = r % n;
    }
    else if (flag == false)
    {
        k = r - r % n - 1;
        if (k > l)
        {
            max = k % n;
        }
        else
        {
            max = r % n;
        }
    }

    printf("%d\n", max);

    return 0;
}