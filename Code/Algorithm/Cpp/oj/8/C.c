#include <stdio.h>
#include <stdbool.h>
#define MAX 310

struct record
{
    int num;
    int math;
    int chinese;
    int eng;
    int sum;
};

void swap(struct record *a, struct record *b);

int main(void)
{
    int n;
    int i = 0, j = 0, key = 0;
    bool flag = true;
    scanf("%d", &n);
    struct record arr[MAX];
    for (i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &arr[i].chinese, &arr[i].math, &arr[i].eng);
        arr[i].sum = arr[i].chinese + arr[i].math + arr[i].eng;
        arr[i].num = i;
    }

    while (flag)
    {
        flag = false;
        for (i = 1; i < n; i++)
        {
            if (arr[i].sum < arr[i + 1].sum)
            {
                swap(&arr[i], &arr[i + 1]);
                flag = true;
            }
        }
    }

    for (i = 2; i <= n; i++)
    {
        for (j = i; j >= 1 && arr[j].sum == arr[j - 1].sum && arr[j].chinese > arr[j - 1].chinese; j--)
        {
            swap(&arr[j], &arr[j - 1]);
        }
    }

    for (i = 2; i <= n; i++)
    {
        for (j = i; j >= 1 && arr[j].sum == arr[j - 1].sum && arr[j].chinese == arr[j - 1].chinese && arr[j].num < arr[j - 1].num; j--)
        {
            swap(&arr[j], &arr[j - 1]);
        }
    }

    for (i = 1; i <= 5; i++)
    {
        printf("%d %d\n", arr[i].num, arr[i].sum);
    }

    return 0;
}

void swap(struct record *a, struct record *b)
{
    struct record temp;
    temp = *a;
    *a = *b;
    *b = temp;
}