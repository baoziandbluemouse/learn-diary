#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i][0];
    for (int i = 0; i < n; i++)
        cin >> a[i][1];
    map<ll, ll> mi, ma;
    for (auto &e : a)
    {
        ll cen = e[0], r = e[1];
        for (ll x = cen - r; x <= cen + r; x++)
        {
            ll y = round(sqrt(r * r - (x - cen) * (x - cen)));
            while (y * y + (x - cen) * (x - cen) > r * r)
                y--;
            mi[x] = min(mi[x], -y);
            ma[x] = max(ma[x], y);
        }
    }
    ll res = 0;
    for (auto &e : mi)
    {
        ll k = e.first;
        ll v = e.second;
        res += ma[k] - v + 1;
    }
    cout << res << "\n";
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