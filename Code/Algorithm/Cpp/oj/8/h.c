#include <stdio.h>
#define MAX 100010
int temp[MAX];
int arr[MAX];
long long cnt;
void merge(int *arr, int low, int mid, int height, int *temp);
void merge_sort(int *arr, int low, int height, int *temp);
int main(void)
{
    int n;
    int i = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    merge_sort(arr, 0, n - 1, temp);
    printf("%lld\n", cnt);
    return 0;
}

void merge(int *arr, int low, int mid, int height, int *temp)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    while (i <= mid && j <= height)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            cnt += mid - i + 1;
        }
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= height)
        temp[k++] = arr[j++];
    for (i = low; i <= height; i++)
    {
        arr[i] = temp[i];
    }
}

void merge_sort(int *arr, int low, int height, int *temp)
{
    if (low >= height)
    {
        return;
    }
    int mid = low + (height - low) / 2;
    merge_sort(arr, low, mid, temp);
    merge_sort(arr, mid + 1, height, temp);
    merge(arr, low, mid, height, temp);
}
