#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
const int N = 4e6;
ll invfac[N + 5], fac[N + 5];
ll qmi(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll inv(ll a)
{
    return qmi(a, MOD - 2);
}

void init()
{
    fac[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
    }
    invfac[N] = inv(fac[N]);
    for (int i = N - 1; i >= 0; i--)
    {
        invfac[i] = invfac[i + 1] * (i + 1) % MOD;
    }
}

ll comb(ll n, ll k)
{
    if (n < 0 || k < 0 || k > n)
        return 0;
    return fac[n] * invfac[k] % MOD * invfac[n - k] % MOD;
}

int main()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ans = 0;
    init();
    for (int i = 0; i <= c; i++)
    {
        ans += comb(c + d - i - 1, d - 1) * comb(a + b + i, b);
        ans %= MOD;
    }
    cout << ans << "\n";
    return 0;
}