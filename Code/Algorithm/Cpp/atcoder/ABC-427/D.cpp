#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> g[N];
string s;
int dp[200005][25][2];

int dfs(int u, int k, int c) // 现在的人在节点u, 还能走k步, 希望最终一定走到c, 是否可能
{
    if (dp[u][k][c] != -1)
        return dp[u][k][c];
    if (k == 0)
    {
        if (s[u] - 'A' == c)
            return 1;
        else
            return 0;
    }
    int ok = 1;
    for (auto v : g[u])
    {
        if (dfs(v, k - 1, c ^ 1) == 0) // 另一个玩家在剩下的k-1最终到不了1-c
            return dp[u][k][c] = 1;
    }
    return dp[u][k][c] = 0;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    k *= 2;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }
    cin >> s;
    s = " " + s;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    if (dfs(1, k, 0) == 1)
        cout << "Alice" << "\n";
    else
        cout << "Bob" << "\n";
}

int main()
{
    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}