#include <bits/stdc++.h>
using namespace std;
const int N = 550;
using ll = long long;
bool vis[N];

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dis(n + 5, vector<ll>(n + 5, 1e18));
    for (int i = 1; i <= n; i++)
    {
        dis[i][i] = 0; // 自己到自己
    }
    for (int i = 1; i <= m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = dis[v][u] = min(dis[u][v], w);
    }
    ll k, kt;
    cin >> k >> kt;
    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        vis[x] = 1;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        ll op, x, y, t;
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y >> t;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    ll nd = min(dis[i][x] + t + dis[y][j], dis[i][y] + t + dis[x][j]);
                    dis[i][j] = min(dis[i][j], nd);
                }
            }
        }
        else if (op == 2)
        {
            int x;
            cin >> x;
            vis[x] = 1;
        }
        else
        {
            vector<ll> air(n + 5, 1e18); // air[i]:i到最近机场的距离
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (vis[j] == 1)
                    {
                        air[i] = min(air[i], dis[i][j]);
                    }
                }
            }
            ll ans = 0;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    ll cur = min(dis[i][j], air[i] + kt + air[j]);
                    if (cur < 1e18)
                    {
                        // 说明到的了
                        ans += cur;
                    }
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}