#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
vector<vector<int>> g(N, vector<int>());
ll ind[N];
ll dp[N]; // dp[i]代表最快的开工完成时间
ll a[N];
int n, m;
void topo()
{
    queue<int> q;
    // 入队无依赖节点
    for (int i = 1; i <= n; i++)
    {
        if (ind[i] == 0)
        {
            dp[i] = a[i]; // 无依赖就直接完成
            q.push(i);
        }
    }
    while (q.size())
    {
        // 可以确保元素只会进入队列一次
        int x = q.front();
        q.pop();
        for (auto &p : g[x])
        {
            ind[p]--;
            dp[p] = max(dp[p], dp[x] + a[p]);
            // 等前面的所有依赖完成了才能开始，dp[p]会多次max计算，取时间最长的
            if (ind[p] == 0)
            {
                q.push(p);
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        // 顺便计算入度
        ind[v]++;
        g[u].push_back(v);
    }
    topo();
    cout << *max_element(dp + 1, dp + 1 + n) << "\n";
}

int main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
