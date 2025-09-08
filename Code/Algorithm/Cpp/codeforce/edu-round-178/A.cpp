#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;
    if ((a + b + c) % 3 == 0)
    {
        ll x = (a + b + c) / 3;
        if (b > x)
        {
            cout << "NO" << "\n";
            return;
        }
        else
        {
            cout << "YES" << "\n";
        }
    }
    else
    {
        cout << "NO" << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}