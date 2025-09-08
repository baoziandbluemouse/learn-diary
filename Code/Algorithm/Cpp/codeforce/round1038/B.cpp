#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll temp_0 = 0;
        ll temp_1 = 0;
        if (a > c)
        {
            temp_0 = a - c;
            ans += temp_0;
        }
        if (b > d)
        {
            temp_1 = (a - temp_0) + b - d;
            ans += temp_1;
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