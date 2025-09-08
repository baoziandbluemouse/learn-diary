#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

vector<vector<int>> g(N, vector<int>());
bitset<N> vis;

void dfs(int u)
{
    vis[u] = true;
    for (auto &v : g[u])
    {
        if (!vis[v])
        {
            vis[v] = true;
            dfs(v);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += g[i].size();
        if (g[i].size() != 2)
        {
            cout << "No" << "\n";
            return 0;
        }
    }
    if (sum != 2 * n)
    {
        cout << "No" << "\n";
        return 0;
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cout << "No" << "\n";
            return 0;
        }
    }
    cout << "Yes" << "\n";
    return 0;
}