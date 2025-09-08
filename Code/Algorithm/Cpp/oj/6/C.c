#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool perfect(int n);

int main(void)
{
    int n;
    scanf("%d", &n);
    bool flag = false;
    int num = 0;

    for (int i = 2; i <= n; i++)
    {
        flag = perfect(i);
        if (flag == false)
        {
            continue;
        }
        else
        {
            num++;
        }
    }

    printf("%d\n", num);
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
