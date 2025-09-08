#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAX 605

int arr[MAX];

int max(int a, int b);

int main(void)
{
    int n, w, x;
    scanf("%d%d", &n, &w);
    int first = 1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        arr[x]++;
        int sum = 0;
        for (int j = 600; i >= 0; j--)
        {
            sum += arr[j];
            if (sum >= max(1, (i * w) / 100))
            {
                if (!first)
                {
                    printf(" ");
                }
                printf("%d", j);
                break;
            }
        }
        first = 0;
    }

    return 0;
}

int max(int a, int b)
{
    return a > b ? a : b;
}