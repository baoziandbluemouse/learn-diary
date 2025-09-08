#include <cstdio>
int cnt = 0;

void solve(int a, int b);
int main(void)
{
    int T = 0;
    int a = 0;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &a);
        cnt = 0;
        if (a == 2)
        {
            printf("1\n");
            continue;
        }
        solve(a, 2);
        printf("%d\n", cnt);
    }

    return 0;
}

void solve(int a, int b)
{
    if (a == 1)
    {
        cnt++;
        return;
    }
    for (int i = b; i <= a; i++)
    {
        if (a % i == 0)
        {
            solve(a / i, i);
        }
    }
}