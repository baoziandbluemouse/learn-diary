#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;
const int MOD = 998244353;
const int N = 2e5 + 10;
const int M = 2e6 + 100;
using ll = long long;
int n, m;
ll a[N];
ll prefix[N];
ll qmi(ll a, int b)
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
    vector<int> v;
    bitset<M> vis;
    vis[0] = vis[1] = 1;
    vector<ll> b(m + 1);
    vector<int> p(n + 1);
    for (int i = 2; i <= M; i++)
    {
        if (!vis[i])
        {
            v.push_back(i);
        }
        for (auto &x : v)
        {
            if (i * x > M)
                break;
            vis[i * x] = 1;
            if (i % x == 0)
                break;
        }
    }
    int idx = 0;
    for (int i = 1; i <= n; i++)
    {
        p[i] = *lower_bound(v.begin(), v.end(), a[i]);
    }
    b[0] = 1;
    for (int i = 1; i <= m; i++)
    {
        b[i] = (qmi(b[i - 1], i) * p[i % n + 1] % MOD + a[i % n + 1] % MOD) % MOD;
    }
    prefix[0] = 1;
    for (int i = 1; i <= m; i++)
    {
        prefix[i] = (prefix[i - 1] * b[i]) % MOD;
    }
}

void solve()
{
    int l, r;
    cin >> l >> r;
    cout << prefix[r] * inv(prefix[l - 1]) % MOD << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    init();
    while (t--)
    {
        solve();
    }
    return 0;
}