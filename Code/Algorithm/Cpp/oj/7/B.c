#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void swap(double *a);

int main()
{
    double save[10000] = {0};
    int x;
    int cnt = 0;
    int cnt2 = 0;
    bool flag = false;
    scanf("%d", &x);

    if (x % 2 != 0)
    {
        printf("-1\n");
        return 0;
    }

    while (x != 1)
    {

        if ((x / 2) % 2 != 0)
        {
            x = x / 2;
            cnt++;
            cnt2++;
            save[cnt2] = pow(2.0, (double)cnt);
        }
        else
        {
            x = x / 2;
            cnt++;
        }
    }

    swap(save);

    for (int i = 1; i < 10000; i++)
    {
        if (save[i] == 0)
        {
            break;
        }
        if (flag)
        {
            printf(" ");
        }
        printf("%.0lf", save[i]);
        flag = true;
    }

    return 0;
}

void swap(double *a)
{
    double *p;
    double *q;
    double temp = 0;
    for (int i = 1; i < 10000 - 1; i++)
    {
        for (int j = i + 1; j < 10000; j++)

        {
            if (a[i] < a[j])
            {
                p = &a[i];
                q = &a[j];
                temp = *p;
                *p = *q;
                *q = temp;
            }
            if (a[j] == 0)
            {
                break;
            }
        }
        if (a[i] == 0)
        {
            break;
        }
    }
}