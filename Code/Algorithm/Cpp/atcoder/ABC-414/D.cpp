#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    vector<ll> b;
    for (int i = 0; i < n - 1; i++)
    {
        ll cal = a[i + 1] - a[i];
        b.push_back(cal);
    }
    sort(b.begin(), b.end(), greater<ll>());
    ll sum = 0;
    for (auto &x : b)
    {
        if (m > 1)
        {
            m--;
            continue;
        }
        sum += x;
    }
    cout << sum << "\n";
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