#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 15;
struct node
{
    int v;
    ll w;
};
ll ans = 4e18;
int n, m;
bitset<N> vis;
vector<vector<node>> g(N, vector<node>());

void dfs(int u, ll cur)
{
    if (u == n)
    {
        ans = min(ans, cur);
    }
    for (auto &i : g[u])
    {
        int v = i.v;
        ll w = i.w;
        if (vis[v])
            continue;
        vis[v] = 1;
        dfs(v, cur ^ w);
        vis[v] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        if (u != v)
        {
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
    }
    vis[1] = 1; // 从1开始
    dfs(1, 0);
    cout << ans << "\n";
    return 0;
}