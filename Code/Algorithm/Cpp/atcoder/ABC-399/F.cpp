#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
using ll = long long;
const ll mod = 998244353;
ll b[13] = {1};
ll a[N];
ll prefix[N];
ll pw[N][13];
ll p[N][13];

ll qmi(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll inv(ll x)
{
    return qmi(x, mod - 2);
}

ll C(ll k, ll j)
{
    if (k < j)
    {
        return 0;
    }
    ll res = 1;
    res = b[k] * inv(b[k - j]) % mod * inv(b[j]) % mod;
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i <= 13; i++)
    {
        b[i] = b[i - 1] * i % mod;
    }
    ll n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = (prefix[i - 1] + a[i]) % mod;
    }
    for (int i = 1; i <= n; i++)
    {
        ll cur = 1;
        for (int j = 0; j <= k; j++)
        {
            pw[i][j] = cur;                           // pw[i][j] prefix[i]的j次方
            p[i][j] = (p[i - 1][j] + pw[i][j]) % mod; // p[i][j] prefix[1]到prefix[i]的j次方的和
            cur = cur * prefix[i] % mod;
        }
    }
    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            int f = 1; // 判断正负
            if ((k - j) % 2 == 1)
                f = -1;
            ll tot = f * C(k, j) % mod * pw[i][j] % mod * p[i - 1][k - j] % mod;
            tot = (tot + mod) % mod;
            res = (res + tot) % mod;
        }
    }
    cout << res << "\n";
    return 0;
}