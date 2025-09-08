#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    ll k;
    cin >> n >> k;
    ll l = -1;
    ll r = 1e18;
    vector<ll> a;
    vector<ll> b;
    vector<ll> c;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        l = max(l, x);
        r = min(r, x);
        a.push_back(x);
    }
    r += k;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        b.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i] != -1)
        {
            c.push_back(b[i] + a[i]);
        }
    }
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    if (c.size() > 1)
    {
        cout << 0 << "\n";
        return;
    }
    else if (c.size() == 1)
    {
        if (c[0] >= l && c[0] <= r)
        {
            cout << 1 << "\n";
            return;
        }
        else
        {
            cout << 0 << "\n";
            return;
        }
    }
    else if (c.size() == 0)
    {
        cout << r - l + 1 << "\n";
        return;
    }
}

int main()
{
    int _t;
    cin >> _t;
    while (_t--)
    {
        solve();
    }
    return 0;
}