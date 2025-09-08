#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4 + 10;
vector<vector<int>> g(N, vector<int>());
vector<int> ans;
ll ind[N];
int n, m;
void topo()
{
    priority_queue<int, vector<int>, greater<int>> q;
    // 入队无依赖节点
    for (int i = 1; i <= n; i++)
    {
        if (ind[i] == 0)
        {
            q.push(i);
        }
    }
    while (q.size())
    {
        // 可以确保元素只会进入队列一次
        int x = q.top();
        q.pop();
        ans.push_back(x);
        for (auto &p : g[x])
        {
            ind[p]--;
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
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        // 顺便计算入度
        ind[v]++;
        g[u].push_back(v);
    }
    topo();
    if (ans.size() != n)
    {
        cout << -1 << "\n";
    }
    else
    {
        for (auto &x : ans)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
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
