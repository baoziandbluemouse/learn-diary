#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m, k;

bool check(ll mid)
{
    ll cnt = (m / (mid + 1)) * mid + (m % (mid + 1));
    cnt = cnt * n;
    return cnt >= k;
}

void solve()
{
    cin >> n >> m >> k;
    ll l = 0, r = 1e9 + 1;
    while (l + 1 < r)
    {
        ll mid = (l + r) / 2;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout << r << "\n";
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