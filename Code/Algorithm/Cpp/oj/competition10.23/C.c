#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAX 200010
long long a[MAX];

void merge(long long *arr, long long low, long long mid, long long height, long long *temp);
void merge_sort(long long *arr, long long low, long long height, long long *temp);
void mergeSort(long long *arr, long long n);

int main()
{
    long long n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        double cur;
        scanf("%lf", &cur);
        a[i] = (long long)(cur * 100);
    }
    mergeSort(a, n);

    long long ptt = 0;
    for (int i = 0; i < 10; i++)
    {
        ptt += a[i];
    }
    for (int i = 0; i < 30; i++)
    {
        ptt += a[i];
    }
    ptt /= 40;
    printf("%.2lf\n", (double)ptt / 100.0);

    return 0;
}

void merge(long long *arr, long long low, long long mid, long long height, long long *temp)
{
    long long i = low;
    long long j = mid + 1;
    long long k = low;
    while (i <= mid && j <= height)
        temp[k++] = arr[i] > arr[j] ? arr[i++] : arr[j++];
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= height)
        temp[k++] = arr[j++];
    for (i = low; i <= height; i++)
    {
        arr[i] = temp[i];
    }
}

void merge_sort(long long *arr, long long low, long long height, long long *temp)
{
    if (low >= height)
    {
        return;
    }
    long long mid = low + (height - low) / 2;
    merge_sort(arr, low, mid, temp);
    merge_sort(arr, mid + 1, height, temp);
    merge(arr, low, mid, height, temp);
}

void mergeSort(long long *arr, long long n)
{
    long long *temp = (long long *)malloc((long long)n * sizeof(long long));
    assert(temp);
    merge_sort(arr, 0, n - 1, temp);
    free(temp);
}