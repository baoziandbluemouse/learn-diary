#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 8010
using namespace std;
int record[MAX];

struct node
{
    int num;
    int id;
} arr[MAX];

bool compare(node x, node y)
{
    if (x.num != y.num)
        return x.num < y.num;
    return x.id < y.id;
}

void get_record(int n);

int main(void)
{
    int n, q;
    scanf("%d%d", &n, &q);
    int i = 1;
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i].num);
        arr[i].id = i;
    }
    sort(arr + 1, arr + n + 1, compare);
    get_record(n);

    for (i = 1; i <= q; i++)
    {
        int v, num_x, work;
        scanf("%d", &work);
        if (work == 1)
        {
            scanf("%d%d", &num_x, &v);
            arr[record[num_x]].num = v;
            for (int j = n; j >= 2; j--)
            {
                if (compare(arr[j], arr[j - 1]))
                {
                    node temp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = temp;
                }
            }
            for (int j = 2; j <= n; j++)
            {
                if (compare(arr[j], arr[j - 1]))
                {
                    node temp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = temp;
                }
            }
            get_record(n);
        }
        else
        {
            scanf("%d", &num_x);
            printf("%d\n", record[num_x]);
        }
    }
    return 0;
}

void get_record(int n)
{
    for (int i = 1; i <= n; i++)
    {
        record[arr[i].id] = i;
    }
}