#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 9;

ll w[N], dp[N];

vector<vector<int>> g(N, vector<int>());

void dfs(int x, int pre)
{
    dp[x] = w[x];
    for (auto &y : g[x])
    {
        if (y == pre)
        {
            continue;
        }
        dfs(y, x);
        dp[x] = max(dp[x], dp[x] + dp[y]);
    }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 0;
        g[i].clear();
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    cout << *max_element(dp + 1, dp + n + 1) << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}