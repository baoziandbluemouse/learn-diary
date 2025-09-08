#include <stdio.h>
#include <string.h>

struct toy
{
    int toward[100010];
    char name[100010][15];
};

int main(void)
{
    struct toy toys;
    int r_l = 0;
    int num = 0;
    int result = 1;
    int i = 0;
    int n, m;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
    {
        scanf("%d%s", &toys.toward[i], toys.name[i]);
    }
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d", &r_l, &num);
        if (r_l == 0)
        {
            if (toys.toward[result] == 0)
            {
                if (result - num < 1)
                {
                    result = n + result - num;
                }
                else
                {
                    result = result - num;
                }
            }
            else
            {
                if (result + num > n)
                {
                    result = result + num - n;
                }
                else
                {
                    result = result + num;
                }
            }
        }
        else
        {
            if (toys.toward[result] == 0)
            {
                if (result + num > n)
                {
                    result = result + num - n;
                }
                else
                {
                    result = result + num;
                }
            }
            else
            {
                if (result - num < 1)
                {
                    result = n + result - num;
                }
                else
                {
                    result = result - num;
                }
            }
        }
    }

    printf("%s\n", toys.name[result]);

    return 0;
}