#include <stdio.h>
#include <stdbool.h>

#define MAX 10010

int array[MAX];

int main(void)
{
    int n;
    int cnt = 0;
    int i = 0;
    int temp = 0;
    bool flag = true;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    while (n-- && flag)
    {
        flag = false;
        for (i = 0; i < n; i++)
        {
            if (array[i] > array[i + 1])
            {
                flag = true;
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                cnt++;
            }
        }
    }

    printf("%d\n", cnt);

    return 0;
}