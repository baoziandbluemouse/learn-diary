#include <bits/stdc++.h>
using namespace std;
const int N = 110;
using ll = long long;
int vis[N];            // 0代表没访问，1代表访问过，2代表访问过两次
vector<ll> c;          // 花费
vector<vector<int>> g; // 记录每个动物园能看哪几种动物
ll ans = LLONG_MAX, n, m;

void dfs(int u, ll pay) // u代表到了第几个动物园，pay代表花费
{
    if (u > n)
    {
        bool key = true;
        for (int i = 1; i <= m; i++)
        {
            if (vis[i] < 2)
            {
                key = false;
                break;
            }
        }
        if (key)
            ans = min(ans, pay);
        return;
    }
    if (pay >= ans)
        return; // 剪枝,后续的pay都比ans大，所以直接返回
    // 不逛这个动物园
    dfs(u + 1, pay);
    // 逛一次这个动物园
    for (auto &x : g[u])
    {
        vis[x]++;
    }
    dfs(u + 1, pay + c[u]);
    for (auto &x : g[u])
    { // 恢复
        vis[x]--;
    }
    // 逛两次这个动物园
    for (auto &x : g[u])
    {
        vis[x] += 2;
    }
    dfs(u + 1, pay + 2 * c[u]);
    for (auto &x : g[u])
    {
        vis[x] -= 2;
    }
}

int main()
{
    cin >> n >> m;
    g.resize(n + 1);
    c.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int num;
        cin >> num;
        for (int j = 1; j <= num; j++)
        {
            int x;
            cin >> x;
            g[x].push_back(i);
        }
    }
    dfs(1, 0);
    cout << ans << "\n";
    return 0;
}