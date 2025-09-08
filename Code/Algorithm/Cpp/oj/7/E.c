#include <stdio.h>

int solve(int a, int n, int first);
int main(void)
{
    int n;
    int a = 0;
    int first = 1;
    scanf("%d", &n);
    for (int i = n; i >= 0; i--)
    {
        scanf("%d", &a);
        first = solve(a, i, first);
    }
    return 0;
}

int solve(int a, int n, int first)
{
    if (first)
    {
        if (n > 1)
        {
            if (a == 1)
            {
                printf("x^%d", n);
                return 0;
            }
            else if (a == -1)
            {
                printf("-x^%d", n);
                return 0;
            }
            if (a == 0)
            {
                return 1;
            }
            printf("%dx^%d", a, n);
            return 0;
        }
        else if (n == 1)
        {
            if (a == 1)
            {
                printf("x");
                return 0;
            }
            else if (a == -1)
            {
                printf("-x");
                return 0;
            }
            if (a == 0)
            {
                return 1;
            }
            printf("%dx", a);
            return 0;
        }
        else
        {
            if (a == 0)
            {
                return 1;
            }
            printf("%d", a);
            return 0;
        }
    }
    if (n > 1)
    {
        if (a > 0)
        {
            if (a == 1)
            {
                printf("+x^%d", n);
                return 0;
            }
            printf("+%dx^%d", a, n);
            return 0;
        }
        else if (a < 0)
        {
            if (a == -1)
            {
                printf("-x^%d", n);
                return 0;
            }
            printf("%dx^%d", a, n);
            return 0;
        }
        else
        {
            return 0;
        }
    }
    else if (n == 1)
    {
        if (a > 0)
        {
            if (a == 1)
            {
                printf("+x");
                return 0;
            }
            printf("+%dx", a);
            return 0;
        }
        else if (a < 0)
        {
            if (a == -1)
            {
                printf("-x");
                return 0;
            }
            printf("%dx", a);
            return 0;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if (a > 0)
        {
            printf("+%d", a);
            return 0;
        }
        else if (a < 0)
        {
            printf("%d", a);
            return 0;
        }
        else
        {
            return 0;
        }
    }
}