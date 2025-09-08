#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define MAX 1100

int arr[MAX];

struct reader
{
    int len;
    int b;
};

void quicksort(int *arr, int left, int right);

int main(void)
{
    int n, q, len, b;
    int i = 0;
    int j = 0;
    struct reader readers[MAX];
    scanf("%d%d", &n, &q);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    quicksort(arr, 0, n - 1);
    for (i = 0; i < q; i++)
    {
        scanf("%d%d", &readers[i].len, &readers[i].b);
    }
    for (i = 0; i < q; i++)
    {
        bool flag = false;
        for (int j = 0; j < n; j++)
        {
            if ((arr[j] % (int)pow(10.0, (double)readers[i].len) == readers[i].b))
            {
                printf("%d\n", arr[j]);
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            printf("-1\n");
        }
    }
    return 0;
}

void quicksort(int *arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int i = left;
    int j = right;
    int pivot = arr[left];
    while (i < j)
    {
        while (i < j && arr[j] >= pivot)
            j--;
        arr[i] = arr[j];
        while (i < j && arr[i] <= pivot)
            i++;
        arr[j] = arr[i];
    }
    arr[i] = pivot;
    quicksort(arr, left, i - 1);
    quicksort(arr, i + 1, right);
}