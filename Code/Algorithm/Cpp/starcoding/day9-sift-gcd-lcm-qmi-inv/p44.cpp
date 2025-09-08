#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p = 998244353;

ll qmi(ll a, ll b)
{
    ll res = 1;
    while (b != 0)
    {
        if (b & 1) // 如果b的二进制最后一位为1
        {
            res = res * a % p;
        }
        a = a * a % p; // 每次循环a都要翻倍
        b >>= 1;
    }
    return res;
}

ll inv(ll x)
{
    return qmi(x, p - 2);
}

ll f(ll x, ll a, ll b, ll c)
{
    return ((a * x % p + b) % p) * inv(c * x % p) % p;
}

void solve()
{
    ll a, b, c, q;
    cin >> a >> b >> c >> q;
    while (q--)
    {
        ll x;
        cin >> x;
        cout << f(x, a, b, c) << "\n";
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}