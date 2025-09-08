#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isprime(ll x)
{
    if (x < 2)
    {
        return false;
    }
    for (ll i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    ll x;
    int k;
    cin >> x >> k;
    if (k == 1)
    {
        if (isprime(x))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    else if (k == 2 && x == 1)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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
