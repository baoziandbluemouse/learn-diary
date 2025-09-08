#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 9;
typedef long long ll;

ll a[N][N], d[N];
bitset<N> intree;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    memset(a, 0x3f, sizeof(a));
    memset(d, 0x3f, sizeof(d));
    for (int i = 1; i <= n; i++)
    {
        a[i][i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        a[u][v] = min(a[u][v], w);
        a[v][u] = min(a[v][u], w);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int u = 1; // u就是我们要找的那个距离intree中的点最近的那个点
        for (int j = 1; j <= n; j++)
        {
            if (intree[u] || (!intree[j] && d[j] < d[u]))
            {
                u = j;
            }
        }
        if (i != 1)
            ans += d[u];
        intree[u] = true;
        d[u] = 0;

        for (int j = 1; j <= n; j++)
        {
            if (intree[j])
                continue;

            d[j] = min(d[j], a[u][j]);
        }
    }
    cout << ans << "\n";
    return 0;
}