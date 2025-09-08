#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
typedef long long ll;

struct node
{
    ll x;
    ll w;
    bool operator<(const node &b) const // 权值最小的优先，如果权值相同，那么用编号区分，编号小大无所谓
    {
        return w == b.w ? x < b.x : w > b.w;
    }
};

vector<vector<node>> g(N, vector<node>());

bitset<N> intree;

ll d[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    memset(d, 0x3f, sizeof(d));
    for (int i = 1; i <= m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    ll ans = 0;
    priority_queue<node> pq;
    pq.push({1, 0});
    d[1] = 0;

    while (pq.size())
    {
        ll u = pq.top().x; // 取出来的点是距离当前intree中的点最近的一个
        pq.pop();
        if (intree[u])
        {
            continue;
        }
        intree[u] = true;
        ans += d[u];
        d[u] = 0;

        // 枚举所有出边
        for (auto &edge : g[u])
        {
            ll y = edge.x;
            ll w = edge.w;
            if (!intree[y] && w < d[y])
            {
                d[y] = w;
                pq.push({y, d[y]});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!intree[i])
        {
            ans = -1;
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}