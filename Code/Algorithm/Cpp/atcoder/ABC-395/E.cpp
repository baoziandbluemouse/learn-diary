#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long ll;

struct node
{
    int v;
    ll w;
    bool operator<(const node &b) const
    {
        return (w == b.w) ? (v < b.v) : (w > b.w);
    }
};

vector<vector<node>> g(N * 2, vector<node>());
ll dis[N * 2];

void dijkstra(int st)
{
    bitset<N * 2> vis;
    memset(dis, 0x3f, sizeof(dis));
    priority_queue<node> q;
    dis[st] = 0ll;
    q.push({st, dis[st]});
    while (q.size())
    {
        int u = q.top().v;
        q.pop();
        if (vis[u])
        {
            continue;
        }
        vis[u] = true;
        for (auto &it : g[u])
        {
            int v = it.v;
            ll w = it.w;
            if (!vis[v] && dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q.push({v, dis[v]});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        ll w = 1;
        cin >> u >> v;
        g[u].push_back({v, w});
        g[v + n].push_back({u + n, w}); // 第二层的图
    }
    for (int i = 1; i <= n; i++)
    {
        g[i].push_back({i + n, k}); // 实现第一层走向第二层，付出k的代价
        g[i + n].push_back({i, k}); // 从第二层回去，付出k的代价
    }

    dijkstra(1);

    cout << min(dis[n], dis[n * 2]) << "\n";
    return 0;
}
