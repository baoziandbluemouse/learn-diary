#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node
{
    int u, v, x, y;
};

void solve()
{
    int n;
    cin >> n;
    vector<int> deg(n, 0);
    vector<vector<int>> g(n);
    vector<vector<int>> gg(n);

    vector<node> e(n - 1);
    for (auto &[u, v, x, y] : e)
    {
        cin >> u >> v >> x >> y;
        u--, v--;
        if (x > y)
        {
            g[u].push_back(v);
            gg[v].push_back(u);
            deg[u]++;
        }
        else
        {
            g[v].push_back(u);
            gg[u].push_back(v);
            deg[v]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (deg[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> p(n);
    for (int i = 1; i <= n; i++)
    {
        int u = q.front();
        p[u] = i;
        q.pop();
        for (const auto &v : gg[u])
        {
            deg[v]--;
            if (deg[v] == 0)
            {
                q.push(v);
            }
        }
    }

    for (int x : p)
    {
        std::cout << x << ' ';
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