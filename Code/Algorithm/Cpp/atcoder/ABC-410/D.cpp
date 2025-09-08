#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n, m;
struct node
{
    int id, w;
};

vector<node> g[N];
bool vis[N][1025]; // vis[i][j]代表点i能否到达状态j

void dfs(int x, int mask)
{
    if (vis[x][mask])
    {
        return;
    }
    vis[x][mask] = 1;
    for (auto &i : g[x])
        dfs(i.id, mask ^ i.w);
}

int main()
{
    cin >> n >> m;
    while (m--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
    }
    dfs(1, 0);
    for (int i = 0; i < 1024; i++)
    {
        if (vis[n][i])
        {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}