#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;

struct node
{
    int v;
    int w;
    bool operator<(const node &b) const
    {
        return (w == b.w) ? (v < b.v) : (w > b.w);
    }
};
vector<vector<node>> g(N, vector<node>());
int dis[N][15];
void dijkstra(int st)
{
    bitset<N> vis;
    for (int i = 0; i < N; i++)
    {
        memset(dis[i], 0x3f, sizeof(dis[i]));
    }
    priority_queue<node> q;
    dis[st][0] = 0;
    q.push({st, dis[st][0]});
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
            int w = it.w;
            if (!vis[v] && dis[v][0] > dis[u][0] + w)
            {
                dis[v][0] = dis[u][0] + w;
                q.push({v, dis[v][0]});
            }
        }
    }
}

void dijkstra1(int st, int p)
{
    bitset<N> vis;
    priority_queue<node> q;
    dis[st][p] = 0;
    q.push({st, dis[st][p]});
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
            int w = it.w;
            if (!vis[v] && dis[v][p] > dis[u][p] + w)
            {
                dis[v][p] = dis[u][p] + w;
                if (p > 0 && dis[u][p - 1] + 0 < dis[v][p])
                {
                    dis[v][p] = dis[u][p - 1] + 0;
                }
                q.push({v, dis[v][p]});
            }
            else if (p > 0 && dis[u][p - 1] + 0 < dis[v][p])
            {
                dis[v][p] = dis[u][p - 1] + 0;
                q.push({v, dis[v][p]});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int st, ed;
    cin >> st >> ed;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (u != v)
        {
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
    }
    dijkstra(st);
    for (int i = 1; i <= k; i++)
    {
        dijkstra1(st, i);
    }
    cout << dis[ed][k] << "\n";
    return 0;
}