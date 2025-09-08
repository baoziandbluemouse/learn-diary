#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int pre[N], cnt[N];

int root(int x)
{
    if (pre[x] == x)
    {
        return x;
    }
    else
    {
        int root_x = root(pre[x]);
        pre[x] = root_x;
        return root_x;
    }
}

void merge(int u, int v)
{
    pre[root(u)] = root(v);
}

void solve(int n, int m)
{
    if (m == 0)
    {
        printf("%d\n", n - 1);
        return;
    }
    memset(pre, 0, sizeof(pre));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++)
    {
        pre[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        merge(u, v);
    }
    for (int i = 1; i <= n; i++)
    {
        cnt[root(i)]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] == n)
        {
            printf("0\n");
            return;
        }
        if (cnt[i])
        {
            ans++;
        }
    }
    printf("%d\n", ans - 1);
}

int main()
{
    int n, m;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }
        scanf("%d", &m);
        solve(n, m);
    }
    return 0;
}