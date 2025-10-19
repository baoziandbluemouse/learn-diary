#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
int dep1[N], dep2[N], dep3[N];
int mx1 = -1, rt1 = -1;
vector<int> g[N];

void dfs(int u, int fa, int dep[])
{
    dep[u] = dep[fa] + 1;
    for (auto v : g[u])
        if (v != fa)
        {
            dfs(v, u, dep);
        }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 1, dep1);
    int mx1 = -1, rt1 = -1;
    for (int i = n; i >= 1; i--)
    {
        if (dep1[i] > mx1)
        {
            mx1 = dep1[i];
            rt1 = i;
        }
    }
    dfs(rt1, rt1, dep2);
    int mx2 = -1, rt2 = -1;
    for (int i = n; i >= 1; i--)
    {
        if (dep2[i] > mx2)
        {
            mx2 = dep2[i];
            rt2 = i;
        }
    }
    dfs(rt2, rt2, dep3);
    for (int i = 1; i <= n; i++)
    {
        if (dep2[i] > dep3[i])
            cout << rt1 << "\n";
        else if (dep3[i] > dep2[i])
            cout << rt2 << "\n";
        else
            cout << max(rt1, rt2) << "\n";
    }
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