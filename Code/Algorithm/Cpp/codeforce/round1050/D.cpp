#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<ll> b;
    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        ll t;
        cin >> t;
        if (t % 2 == 0)
        {
            res += t;
        }
        else
        {
            b.push_back(t);
        }
    }
    if (b.empty())
    {
        cout << 0 << "\n";
    }
    else
    {
        sort(b.begin(), b.end(), greater<ll>());
        int len = (b.size() + 1) / 2;
        for (int i = 0; i < len; i++)
        {
            res += b[i];
        }
        cout << res << "\n";
    }
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