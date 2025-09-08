#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool perfect(int n);

int change(const int n);

int main(void)
{
    bool flag = false;

    int change_new = 0;

    for (int i = 100; i <= 999; i++)
    {
        flag = perfect(i);
        if (flag == false)
        {
            continue;
        }
        else
        {
            change_new = change(i);
            if (change_new == i)
            {
                printf("%d\n", i);
            }
            else
            {
                continue;
            }
        }
    }

    return 0;
}

bool perfect(int n)
{

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int change(const int n)
{
    int x = n;
    int new = 0;
    while (x != 0)
    {
        new = new * 10 + x % 10;
        x = x / 10;
    }

    return new;
}