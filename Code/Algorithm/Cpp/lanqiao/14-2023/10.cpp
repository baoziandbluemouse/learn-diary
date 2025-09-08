#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 20;
int n, m, hp;
int at[N]; // 每只怪的攻击力
struct node
{
    int v;   // 出点
    int val; // 权值
};
struct node2
{
    int u;   // 当前点
    int hp;  // 剩余血量
    int val; // 到源点的距离
    bool operator<(const node2 &a) const
    {
        if (a.hp != hp)
        {
            return a.hp < hp; // 血量大的优先级高
        }
        else
        {
            return a.val > val; // 距离小的优先级高
        }
    }
};

vector<node> g[N];
int dis[N];     // 到源点的距离
bitset<N> vis2; // 标记怪物是否已被杀死
bitset<N> vis;  // 标记数组

void dijkstra(int st)
{
    memset(dis, 0x3f, sizeof(dis));
    dis[st] = 0; // 源点距离为0
    priority_queue<node2> pq;
    pq.push({st, hp, 0}); // 源点入队
    while (pq.size())
    {
        auto t = pq.top(); // 取出当前点
        pq.pop();
        int u = t.u; // 当前点
        if (vis[u])
        {
            continue; // 如果已经访问过，跳过
        }
        if (vis2[u])
        {
            vis[u] = true; // 如果怪物被击杀，证明最优点
        }
        for (auto &it : g[u]) // 遍历当前点的所有出边
        {
            int v = it.v;            // 出点
            int w = it.val;          // 权值
            int cur_hp = t.hp;       // 血量
            if (dis[v] > dis[u] + w) // 如果到出点的距离大于到当前点的距离加上权值
            {
                dis[v] = dis[u] + w;
                for (auto &it2 : g[v])
                {
                    int v2 = it2.v;
                    int at2 = at[v2];
                    cur_hp -= at2;
                }
                if (cur_hp > 0) // 如果血量大于0，入队
                {
                    pq.push({v, cur_hp, dis[v]});
                    vis2[v] = true;
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m >> hp;
    for (int i = 0; i <= n - 1; i++)
    {
        cin >> at[i];
    }
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
    dijkstra(0);
    for (int i = 0; i <= n - 1; i++)
    {
        if (!vis2[i])
        {
            cout << -1 << "\n";
            return 0;
        }
    }
    if (dis[n - 1] == 0x3f3f3f3f)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << dis[n - 1] << "\n";
    }
    return 0;
}