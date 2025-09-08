#include <stdio.h>
#include <stdlib.h>

void solve(int n, int *p, int *f)
{
    int p_min = p[0];
    int f_max = f[0];
    for (int i = 1; i < n; i++)
    {
        if (p[i] < p_min)
        {
            p_min = p[i];
        }
        if (f[i] > f_max)
        {
            f_max = f[i];
        }
    }
    printf("%d %d\n", p_min, f_max);
}

int main(void)
{
    int t;
    int n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int *p = (int *)malloc(n * sizeof(int));
        int *f = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &p[i]);
            scanf("%d", &f[i]);
            f[i] += p[i];
        }
        solve(n, p, f);
        free(p);
        free(f);
    }
    return 0;
}