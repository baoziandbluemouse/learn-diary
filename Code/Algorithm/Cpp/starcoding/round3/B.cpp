#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll v;
    int n;
    cin >> v >> n;
    vector<ll> a;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (bitset<32>(x).count() == 1)
        {
            a.push_back(x);
        }
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int ans = 0;
    for (auto &x : a)
    {
        if (x > v)
        {
            continue;
        }
        if (x & v)
        {
            ans++;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}