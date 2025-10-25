#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
using ll = long long;

void solve()
{
    ll sum = 0;
    int n, c;
    ll m;
    cin >> n >> m >> c;
    vector<ll> a;
    map<ll, int> cnt;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        a.emplace_back(x);
        cnt[x]++;
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int p = a.size();
    int j = 0;
    if (a[0] == 0)
    {
        j = 1;
    }
    ll idx = 0;
    ll i = 0;
    while (i <= m - 1)
    {
        ll x = 0;
        while (x < c)
        {
            idx = a[j];
            x += cnt[a[j]];
            if (x >= c)
            {
                sum += (idx - i) * x;
                i = idx;
            }
            j++;
            if (j == p)
            {
            }
        }
        if (j == p)
        {
            ll t = 0;
            for (auto &l : a)
            {
                t += cnt[l];
                if (t >= c)
                {
                    break;
                }
            }
            sum += (m - 1 - i) * t;
            i = m - 1;
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