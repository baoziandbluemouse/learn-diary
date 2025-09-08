#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
struct node
{
    ll a, w;
    bool operator<(const node &n) const
    {
        return (w == n.w) ? (a < n.a) : (w > n.w);
    }
};
vector<vector<node>> g(N, vector<node>());
ll dis[N];
bitset<N> vis;

void dijkstra(int st)
{
    // 初始化
    priority_queue<node> q; // 此处的权值w代表到达该点需要的距离
    memset(dis, 0x3f, sizeof(dis));
    // 置入起点
    q.push({st, 0});
    dis[st] = 0; // 到达起点的距离为0
    // 开始
    while (q.size())
    {
        ll u = q.top().a;
        q.pop();
        if (vis[u]) // 跳过冗余点
        {
            continue;
        }
        vis[u] = true; // 经过优先队列筛选，是最优的(st直接就判断是最优)
        // 遍历
        for (const auto &i : g[u])
        {
            ll v = i.a, w = i.w;
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
    cout.tie(0);
    int n, m, st;
    cin >> n >> m >> st;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (u != v) // 避免自环
        {
            g[u].push_back({v, w});
        }
    }
    dijkstra(st);
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
    cout << "\n";
    return 0;
}