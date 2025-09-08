#include <stdio.h>
#include <string.h>
#define MAX 200010

int coordinate_x[MAX];
int coordinate_y[MAX];

int main(void)
{
    int n, i, j;
    int cnt_max = -1;
    int cnt = 0;

    char str;

    scanf("%d", &n);

    while (getchar() != '\n')
    {
        continue;
    }

    for (i = 0; i < n; i++)
    {
        str = getchar();

        if (str == 'U')
        {
            coordinate_y[i]++;
        }
        else if (str == 'D')
        {
            coordinate_y[i]--;
        }

        if (str == 'R')
        {
            coordinate_x[i]++;
        }
        else if (str == 'L')
        {
            coordinate_x[i]--;
        }
    }

    for (i = 0; i < n; i++)
    {
        cnt = 0;
        for (j = 0; j < n; j++)
        {
            if (coordinate_x[i] == coordinate_x[j] & coordinate_y[i] == coordinate_y[j])
            {
                cnt++;
            }
            if (cnt > cnt_max)
            {
                cnt_max = cnt;
            }
        }
    }

    printf("%d\n", cnt_max);

    return 0;
}