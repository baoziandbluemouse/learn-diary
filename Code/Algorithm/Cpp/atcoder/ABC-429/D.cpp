#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
using ll = long long;
ll a[N];

void solve()
{
    ll n, m, c;
    ll ans = 0;
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        a[n + i] = a[i] + m;
    for (int i = 1; i <= n; i++)
    {
        int p = upper_bound(a + 1, a + 1 + 2 * n, a[i + c]) - a - 1;
        ans += 1ll * (p - i) * (a[i + 1] - a[i]);
    }
    cout << ans;
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