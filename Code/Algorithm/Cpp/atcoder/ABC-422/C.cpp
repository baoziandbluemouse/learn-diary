#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;
    ll x = min(a, c);
    ll y = (a + b + c) / 3;
    cout << min(x, y) << "\n";
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