#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
vector<int> g[N];
int vis[N];

int dfs(int u)
{
    vis[u] = true;
    int cnt = 1;
    for (int y : g[u])
    {
        if (!vis[y])
        {
            cnt += dfs(y);
        }
    }
    return cnt;
}

// 计算从 start 到各个节点的最短路长度
// 如果节点不可达，则最短路长度为 -1
// 节点编号从 0 到 n-1，边权均为 1
vector<int> bfs(int n, vector<vector<int>> &edges, int start)
{
    vector<vector<int>> g(n);
    for (auto &e : edges)
    {
        int x = e[0], y = e[1];
        g[x].push_back(y);
        g[y].push_back(x); // 无向图
    }

    vector<int> dis(n, -1); // -1 表示尚未访问到
    queue<int> q;
    dis[start] = 0;
    q.push(start);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int y : g[x])
        {
            if (dis[y] < 0)
            {
                dis[y] = dis[x] + 1;
                q.push(y);
            }
        }
    }
    return dis;
}
