#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(m);
    vector<ll> l(n, -1); // 前缀  l[i]代表的是a[i]作为被摘走的花后，下一朵要摘的b[i]花的下标
    vector<ll> r(n, -1); // 后缀
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    int bi = 0;
    for (int i = 0; i < n; i++)
    {
        if (bi < m && a[i] >= b[bi])
        {
            bi++;
        }
        l[i] = bi;
    }
    bi = m - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (bi >= 0 && a[i] >= b[bi])
        {
            bi--;
        }
        r[i] = bi;
    }
    if (l[n - 1] == m)
    {
        cout << 0 << endl;
        return;
    }
    ll ans = 1e18;
    // 边界处理
    if (l[n - 1] == m - 1)
    {
        ans = min(ans, b[m - 1]);
    }
    if (r[0] == 0)
    {
        ans = min(ans, b[0]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (l[i] == r[i + 1])
        {
            ans = min(ans, b[l[i]]);
        }
    }
    if (ans == 1e18)
        cout << -1 << "\n";
    else
        cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}