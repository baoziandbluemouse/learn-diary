#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
using ll = long long;
int vis[N], f[N], ans[N];
vector<int> g[N];
// vis[i] -> 第i个点被访问的次数
// f[i] -> 点i是从哪个S过来的
// ans[i] -> 第i个点到2个最近的S 距离之和

void solve()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    string s;
    cin >> s;
    s = " " + s;
    queue<array<int, 3>> q;
    for (int i = 1; i <= n; i++)
    {
        // 将所有S点入队
        if (s[i] == 'S')
        {
            q.push({i, 0, i}); // 当前点，已经走的距离，以及这个点是从哪个S过来的
            vis[i] = 1;
            f[i] = i;
        }
    }
    while (q.size())
    {
        auto [u, d, src] = q.front();
        // u: 当前点  d:已经走的距离  src:这个点是从哪个S过来的
        q.pop();
        for (int v : g[u])
        {
            if (vis[v] != 2 && f[v] != src)
            {
                // vis只能为0和1，表示第一次和第二次到达
                ans[v] += d + 1;
                vis[v]++;
                f[v] = src;
                q.push({v, d + 1, src});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'D')
        {
            cout << ans[i] << "\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}