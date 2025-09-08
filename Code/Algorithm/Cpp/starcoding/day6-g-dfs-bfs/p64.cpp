#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;

bitset<N> vis;
vector<vector<int>> g(N, vector<int>());

void dfs(int x)
{
    vis[x] = true;
    for (auto &y : g[x])
    {
        if (vis[y])
            continue;
        dfs(y);
    }
}

void bfs(int x)
{
    queue<int> q;
    q.push(x);
    while (q.size())
    {
        int x = q.front();
        q.pop();
        vis[x] = true;
        for (auto &y : g[x])
        {
            if (vis[y])
                continue;
            q.push(y);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    dfs(1);
    // bfs(1);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            cout << i << " ";
    }
    cout << "\n";
    return 0;
}