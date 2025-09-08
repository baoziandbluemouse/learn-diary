#include <stdio.h>

void solve(int n, int m);
int main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);
    solve(n, m);
    return 0;
}

void solve(int n, int m)
{
    if (n == 0)
    {
        return;
    }
    int x = n % m;
    solve(n / m, m);
    switch (x)
    {
    case 10:
        printf("A");
        break;
    case 11:
        printf("B");
        break;
    case 12:
        printf("C");
        break;
    case 13:
        printf("D");
        break;
    case 14:
        printf("E");
        break;
    case 15:
        printf("F");
        break;
    default:
        printf("%d", x);
        break;
    }
}
