#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e7 + 10;
const ll p = 1e9 + 7;

ll fac[N];

void init(int n)
{
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fac[i] = fac[i - 1] * i % p;
    }
}

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

ll C(ll n, ll m)
{
    if (n < 0 || m < 0 || n < m)
    {
        return 0;
    }
    ll res = fac[n] * inv(fac[n - m] * fac[m] % p) % p;
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init(1e7);
    int q;
    cin >> q;
    while (q--)
    {
        ll n, m;
        cin >> n >> m;
        ll ans = C(n, m);
        cout << ans << "\n";
    }
    return 0;
}