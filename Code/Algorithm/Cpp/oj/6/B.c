#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int perfect(int n);

int main(void)
{
    int n;
    scanf("%d", &n);
    int l = 0;

    for (int i = 2; i <= n; i++)
    {
        l = perfect(i);
        if (l == -1)
        {
            continue;
        }
        else
        {
            printf("%d\n", l);
        }
    }

    return 0;
}

int perfect(int n)
{
    int sum = 1;
    bool flag = false;

    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0 && i != 1)
        {
            sum = sum + i + (n / i);
        }
    }

    if (sum == n)
    {
        flag = true;
    }

    if (flag == true)
    {
        return n;
    }
    else
    {
        return -1;
    }
}
