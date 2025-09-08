#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    for (int bit = 30; bit >= 0; bit--)
    {
        ll v = 1ll << bit;
        ll cost = m * v;
        if (n >= cost)
        {
            ans |= (1ll << bit);
            n -= cost;
        }
        else
        {
            cost -= m;
            if (n <= cost)
            {
                continue;
            }
            ll k = (n - cost + v - 1) / v;
            n -= k * v;
        }
    }
    cout << ans << "\n";
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