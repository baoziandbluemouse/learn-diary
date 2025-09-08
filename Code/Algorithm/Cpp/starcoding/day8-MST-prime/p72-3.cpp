#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
typedef long long ll;

struct node
{
    ll u;
    ll v;
    ll w;
    bool operator<(const node &b) const // 权值最小的优先，如果权值相同就用编号区分，编号小大无所谓
    {
        if (w != b.w)
        {
            return w < b.w;
        }
        if (u != b.u)
        {
            return u < b.u;
        }
        return v < b.v;
    }
};
ll pre[N];

ll root(ll x)
{
    if (pre[x] == x)
    {
        return x;
    }
    else
    {
        ll root_x = root(pre[x]);
        pre[x] = root_x;
        return root_x;
    }
}

void merge(ll x, ll y)
{
    pre[root(x)] = root(y);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = i;
    }
    vector<node> es;
    for (int i = 1; i <= m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        es.push_back({u, v, w});
    }
    ll ans = 0;
    sort(es.begin(), es.end());
    for (auto &e : es)
    {
        ll u = e.u;
        ll v = e.v;
        ll w = e.w;
        if (root(u) == root(v))
        {
            continue;
        }
        merge(u, v);
        ans += w;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        if (root(i) != root(i + 1))
        {
            ans = -1;
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}