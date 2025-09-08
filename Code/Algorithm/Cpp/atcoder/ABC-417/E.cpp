#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;
using ll = long long;
const int N = 1010;
int pre[N];

int root(int x)
{
    if (pre[x] == x)
    {
        return x;
    }
    else
    {
        int root_x = root(pre[x]);
        pre[x] = root_x;
        return root_x;
    }
}

void merge(int x, int y)
{
    int a = root(x);
    int b = root(y);
    if (a == b)
    {
        return;
    }
    pre[a] = b;
}

void solve()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<int>> g(n + 5);
    vector<array<int, 2>> edge;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        edge.push_back({u, v});
    }
    for (int i = 1; i <= n; i++)
    {
        // 将存边排序，保证优先用字典序小的数字
        sort(g[i].begin(), g[i].end());
    }
    vector<int> vis(n + 5);
    vector<int> ans = {x}; // 存答案，起点是x
    vis[x] = 1;
    while (ans.back() != y)
    {
        for (int i = 1; i <= n; i++)
        {
            pre[i] = i;
            // 初始化并查集
        }
        for (auto [u, v] : edge)
        {
            if (!vis[u] && !vis[v])
                merge(u, v);
        }
        int cur = ans.back();
        for (auto v : g[cur])
        {
            // 找到可以走的连边里，能到达终点的
            if (!vis[v] && root(v) == root(y))
            {
                ans.push_back(v);
                vis[v] = 1;
                break;
            }
        }
    }
    for (auto &x : ans)
    {
        cout << x << " ";
    }
    cout << "\n";
}

int main()
{
    int _;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}