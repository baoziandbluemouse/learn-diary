#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int sum(int n);
bool ispeace(int sum, int n);

int main(void)
{
    int sum1 = 0;
    bool flag = false;

    for (int i = 2;; i++)
    {
        sum1 = sum(i);
        if (sum1 == i)
        {
            continue;
        }
        flag = ispeace(sum1, i);

        if (flag == true)
        {
            printf("%d %d\n", i, sum1);
            return 0;
        }
    }
}

int sum(int n)
{
    int sum = 1;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (i != n / i)
            {
                sum = sum + i + (n / i);
            }
        }
    }

    return sum;
}

bool ispeace(int sum, int n)
{
    int sum_new = 1;
    for (int i = 2; i <= sqrt(sum); i++)
    {
        if (sum % i == 0)
        {
            sum_new = sum_new + i + (sum / i);
        }
    }

    if (sum_new == n)
    {
        return true;
    }

    return false;
}