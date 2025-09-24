#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 105, MOD = 998244353;
int n, a[N], b[N];
ll f[N], g[N];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    f[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        f[i] = g[i] = 0;
        if (a[i - 1] <= a[i] && b[i - 1] <= b[i])
        {
            f[i] += f[i - 1];
            g[i] += g[i - 1];
        }
        if (a[i - 1] <= b[i] && b[i - 1] <= a[i])
        {
            f[i] += g[i - 1];
            g[i] += f[i - 1];
        }
        f[i] %= MOD;
        g[i] %= MOD;
    }
    cout << (f[n] + g[n]) % MOD << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
    return 0;
}