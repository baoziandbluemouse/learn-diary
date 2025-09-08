#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 9;
typedef long long ll;

struct node
{
    int x, w; // x表示出点，w表示权值
};
vector<vector<node>> g(N, vector<node>());
ll d[N], n, m;

void dijkstra(int st)
{
    memset(d, 0x3f, sizeof(ll) * (n + 1));
    d[st] = 0;
    bitset<N> vis; // 记录已经被拓展过的
    for (int i = 1; i <= n - 1; i++)
    {
        // 找出最小点（距离源点最近的点）
        int u = 1;
        for (int j = 1; j <= n; j++)
        {
            if (vis[u] || (!vis[j] && d[j] < d[u]))
            {
                u = j;
            }
        }

        // 表示u已被拓展
        vis[u] = true;

        // 此时d[u]已为最优的，别的不一定
        for (const auto &edge : g[u])
        {
            int v = edge.x;
            int w = edge.w;
            if (!vis[v] && d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (u != v) // 避免自环
        {
            g[u].push_back({v, w});
        }
    }

    dijkstra(1);

    cout << (d[n] >= 0x3f3f3f3f ? -1 : d[n]) << "\n"; // 输出d[n]，若d[n]未被更新，则输出-1(即d[n]>=0x3f3f3f3f)

    return 0;
}