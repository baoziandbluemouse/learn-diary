#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
const int N = 1e6 + 10;
ll a[N], prefix[N];

ll qmi(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll inv(ll a)
{
    return qmi(a, mod - 2);
}

int main()
{
    int n;
    ll x, m, k;
    cin >> n >> x >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll p = inv(qmi(2, k));
    for (int i = 1; i <= k; i++)
    {
        prefix[i] = (a[i] + (a[i] & m) + x) % mod;
    }
    ll ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += (ans + qmi(a[i] * p % mod, k - 1) + qmi(prefix[i] * p % mod, k - 1)) % mod;
    }
    for (int i = k + 1; i <= n; i++)
    {
        ans = (ans + a[i]) % mod;
    }
    cout << ans << "\n";
    return 0;
}