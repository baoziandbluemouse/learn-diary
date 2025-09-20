#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int deg[N];
int vis[N];
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1, vector<int>());
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x == 0 && y == 0)
        {
            continue;
        }

        if (x != i)
        {
            deg[i]++;
            g[x].push_back(i);
        }
        else
        {
            deg[i]++;
        }

        if (y != i)
        {
            deg[i]++;
            g[y].push_back(i);
        }
        else
        {
            deg[i]++;
        }
    }
    int ans = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 0)
        {
            q.push(i);
            ans++;
        }
    }
    while (q.size())
    {
        int t = q.front();
        q.pop();
        for (auto &x : g[t])
        {
            deg[x]--;
            if ((deg[x] == 0 || deg[x] == 1) && vis[x] == 0)
            {
                ans++;
                vis[x] = 1;
                q.push(x);
            }
        }
    }
    cout << ans << "\n";
}

int main()
{
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}