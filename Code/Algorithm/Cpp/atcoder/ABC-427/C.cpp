#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int ans = 1e9, n, m;
vector<int> g[N];
int vis[N];

void dfs(int dep)
{
    if (dep > n)
    {
        int tem = 0;
        vector<int> rec(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            for (auto &v : g[i])
            {
                if (rec[v] != 1 && vis[v] == vis[i])
                {
                    tem++;
                }
            }
            rec[i] = 1;
        }
        ans = min(ans, tem);
        return;
    }
    // 分组1
    vis[dep] = 1;
    dfs(dep + 1);
    vis[dep] = -1;
    // 分组2
    vis[dep] = 2;
    dfs(dep + 1);
    vis[dep] = -1;
}

void solve()
{
    memset(vis, -1, sizeof(vis));
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    cout << ans << "\n";
}

int main()
{
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}