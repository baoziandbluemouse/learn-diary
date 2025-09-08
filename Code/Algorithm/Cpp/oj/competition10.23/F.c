#include <stdio.h>
#include <math.h>

int factor(long long n, long long *arr);

void quicksort(long long *arr, int left, int right);

int main(void)
{
    long long n;
    long long arr[100000] = {0};
    scanf("%lld", &n);

    int cnt = factor(n, arr);
    quicksort(arr, 0, cnt - 1);

    int num = 0;
    int i = 1;
    while (n != 0)
    {
        if (n - arr[i] > 0 && arr[i] != 1)
        {
            n -= arr[i];
            num++;
        }
        else if (arr[i] == 1)
        {
            n -= arr[i];
            num++;
        }
        else
        {
            i++;
        }
    }

    if (num % 2 == 0)
    {
        printf("Hikari\n");
    }
    else
    {
        printf("Tairitsu\n");
    }

    return 0;
}

int factor(long long n, long long *arr)
{
    int i = 1;
    int cnt = 0;
    for (i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            arr[cnt] = i;
            cnt++;
            arr[cnt] = n / i;
            cnt++;
        }
    }
    return cnt;
}

void quicksort(long long *arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int i = left;
    int j = right;
    long long pivot = arr[left];
    while (i < j)
    {
        while (i < j && arr[j] <= pivot)
        {
            j--;
        }
        arr[i] = arr[j];
        while (i < j && arr[i] >= pivot)
        {
            i++;
        }
        arr[j] = arr[i];
    }
    arr[i] = pivot;
    quicksort(arr, left, i - 1);
    quicksort(arr, i + 1, right);
}