#include <stdio.h>
#include <stdbool.h>
#define MAX 5010

struct record
{
    long long num;
    double score;
};

void quicksort(struct record *arr, int left, int right);

int main(void)
{
    int n, m;
    int i = 0, j = 0;
    int cnt = 0;
    scanf("%d%d", &n, &m);
    struct record arr[MAX];
    for (i = 1; i <= n; i++)
    {
        scanf("%lld%lf", &arr[i].num, &arr[i].score);
    }
    quicksort(arr, 1, n);

    printf("%lld %.2lf\n", arr[m].num, arr[m].score);
    return 0;
}

void quicksort(struct record *arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int i = left;
    int j = right;
    struct record pivot = arr[left];
    while (i < j)
    {
        while (i < j && arr[j].score <= pivot.score)
            j--;
        arr[i] = arr[j];
        while (i < j && arr[i].score >= pivot.score)
            i++;
        arr[j] = arr[i];
    }

    arr[i] = pivot;

    quicksort(arr, left, i - 1);
    quicksort(arr, i + 1, right);
}
