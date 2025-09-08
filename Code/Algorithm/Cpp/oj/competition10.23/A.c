#include <stdio.h>
#define MAX 200010
long long arr[MAX] = {0, 6, 1, 6};
int x_list[MAX];

long long solve(int x);
int main(void)
{
    int q;
    int max = -1;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &x_list[i]);
        if (x_list[i] > max)
        {
            max = x_list[i];
        }
    }

    for (int i = 4; i <= max; i++)
    {
        arr[i] = (7 * arr[i - 1] + 6 * arr[i - 2] + 5 * arr[i - 3]) % 998244353;
    }

    for (int i = 0; i < q; i++)
    {
        printf("%lld\n", arr[x_list[i]]);
    }

    return 0;
}
