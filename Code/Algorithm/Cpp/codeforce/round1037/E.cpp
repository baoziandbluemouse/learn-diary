#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n), s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    auto check = [&]() -> bool
    {
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            a[i] = ll(p[i]) * s[i] / gcd(p[i], s[i]);
        }
        ll x = a[0];
        for (int i = 0; i < n; i++)
        {
            x = gcd(x, a[i]);
            if (x != p[i])
            {
                return false;
            }
        }
        x = a[n - 1];
        for (int i = n - 1; i >= 0; i--)
        {
            x = gcd(x, a[i]);
            if (x != s[i])
            {
                return false;
            }
        }
        return true;
    };
    cout << (check() ? "YES" : "NO") << "\n";
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