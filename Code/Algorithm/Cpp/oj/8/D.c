#include <stdio.h>
#include <stdbool.h>
#define MAX 5010

struct record
{
    int num;
    int score;
};

void quicksort(struct record *arr, int left, int right);

void swap(struct record *a, struct record *b);

int main(void)
{
    int n, m;
    int i = 0, j = 0;
    int cnt = 0;
    scanf("%d%d", &n, &m);
    struct record arr[MAX];
    for (i = 1; i <= n; i++)
    {
        scanf("%d%d", &arr[i].num, &arr[i].score);
    }
    quicksort(arr, 1, n);

    int h = 1;
    while (h < (n / 3))
    {
        h = h * 3 + 1;
    }

    while (h > 0)
    {
        for (i = h; i <= n; i++)
        {
            for (j = i; j >= h && arr[j].score == arr[j - h].score && arr[j].num > arr[j - h].num; j -= h)
            {
                swap(&arr[j], &arr[j - h]);
            }
        }
        h = h / 3;
    }

    int scoreline = arr[n - (int)(m * 1.5) + 1].score;

    for (i = n; i > 0; i--)
    {
        if (arr[i].score >= scoreline)
        {
            cnt++;
        }
        else
        {
            break;
        }
    }

    printf("%d %d\n", scoreline, cnt);
    for (i = n; i > n - cnt; i--)
    {
        printf("%d %d\n", arr[i].num, arr[i].score);
    }

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
        while (i < j && arr[j].score >= pivot.score)
            j--;
        arr[i] = arr[j];
        while (i < j && arr[i].score <= pivot.score)
            i++;
        arr[j] = arr[i];
    }

    arr[i] = pivot;

    quicksort(arr, left, i - 1);
    quicksort(arr, i + 1, right);
}

void swap(struct record *a, struct record *b)
{
    struct record temp = *a;
    *a = *b;
    *b = temp;
}