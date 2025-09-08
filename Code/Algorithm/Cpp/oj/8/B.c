#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

int array[MAX];
int array_new[MAX];

int main(void)
{
    int n;
    int i = 0;
    int j = 0;
    int k = 0;
    int cnt = 0;
    int temp = 0;
    bool flag = true;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (array[i] == array[j])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            array_new[cnt] = array[i];
            cnt++;
        }
        flag = true;
    }

    for (i = 0; i < cnt; i++)
    {
        k = i;
        for (j = i + 1; j < cnt; j++)
        {
            if (array_new[j] < array_new[k])
            {
                k = j;
            }
        }
        if (k != i)
        {
            temp = array_new[i];
            array_new[i] = array_new[k];
            array_new[k] = temp;
        }
    }

    printf("%d\n", cnt);

    for (i = 0; i < cnt; i++)
    {
        printf("%d", array_new[i]);
        if (i != n - 1)
        {
            printf(" ");
        }
    }

    return 0;
}