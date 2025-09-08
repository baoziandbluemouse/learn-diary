#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

void solve()
{
    ll a, b, k;
    cin >> a >> b >> k;
    if (a <= k && b <= k)
    {
        cout << 1 << "\n";
    }
    else
    {
        ll p = gcd(a, b);
        if (a / p <= k && b / p <= k)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 2 << "\n";
        }
    }
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