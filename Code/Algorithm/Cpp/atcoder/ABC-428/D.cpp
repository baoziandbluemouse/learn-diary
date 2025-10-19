#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll c, d;
    cin >> c >> d;
    ll ans = 0, base = 1; // base 是 10^{d-1}
    for (int l = 0; l <= 18; ++l)
    {
        ll L = max(base - c, 1ll);
        ll R = min(d, 10 * base - c - 1);
        if (L <= R)
        {
            ans += (int) sqrtl(R + c * (base * 10 + 1)) - (int) sqrtl(L - 1 + c * (base * 10 + 1));
        }
        base *= 10;
    }
    cout << ans << "\n";
}

int main()
{
    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}