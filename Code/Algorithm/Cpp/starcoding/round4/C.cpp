#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e12 + 5;
const int N = 2005;

void solve()
{
    ll d;
    cin >> d;
    ll ans = d;
    for (ll x = 0; x * x <= d; ++x)
    {
        ll l = 0, r = 1e7;
        while (l + 1 != r)
        {
            ll mid = (l + r) >> 1;
            if (mid * mid <= d - x * x)
                l = mid;
            else
                r = mid;
        }
        ll y = l;
        ans = min(ans, abs(x * x + y * y - d));
        y = r;
        ans = min(ans, abs(x * x + y * y - d));
    }
    cout << ans << '\n';
}

int main()
{
    int _ = 1;
    while (_--)
        solve();
    return 0;
}