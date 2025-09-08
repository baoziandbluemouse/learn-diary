#include <stdio.h>
#define MAX 1010
long long cnt;
void merge(int *arr, int low, int mid, int height, int *temp);
void merge_sort(int *arr, int low, int height, int *temp);
void solve(int n, int i);
int main(void)
{
    int T;
    int n;
    int i = 0;
    scanf("%d", &T);
    for (i = 1; i <= T; i++)
    {
        scanf("%d", &n);
        solve(n, i);
        printf("\n");
    }
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

void solve(int n, int i)
{
    int temp[MAX] = {0};
    int arr[MAX] = {0};
    cnt = 0;
    for (int j = 0; j < n; j++)
    {
        scanf("%d", &arr[j]);
    }
    merge_sort(arr, 0, n - 1, temp);
    printf("Scenario #%d:\n", i);
    printf("%lld\n", cnt);
}