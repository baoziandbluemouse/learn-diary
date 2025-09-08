#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e7 + 10;
const ll p = 1e9 + 7;

ll fac[N], invfac[N]; // 预处理阶乘，逆元

ll qmi(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = res * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

ll inv(ll x)
{
    return qmi(x, p - 2);
}

void init(int n)
{
    fac[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        fac[i] = fac[i - 1] * i % p;
    }
    invfac[n] = inv(fac[n]);
    for (ll i = n - 1; i >= 0; i--)
    {
        invfac[i] = invfac[i + 1] * (i + 1) % p;
    }
}

ll C(ll n, ll m)
{
    if (n < 0 || m < 0 || n < m)
    {
        return 0;
    }
    ll res = fac[n] * invfac[n - m] % p * invfac[m] % p;
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init(1e7);
    ll q, a, b, c, n, m;
    cin >> q >> a >> b >> c;
    cin >> n >> m;
    ll ans = 0;
    for (int i = 1; i <= q; i++)
    {
        ans = (ans + C(n, m)) % p;
        n = (n * a % c + b) % c;
        m = (m * b % c + a) % c;
    }
    cout << ans << "\n";
    return 0;
}