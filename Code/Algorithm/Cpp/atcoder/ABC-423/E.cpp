#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
using ll = long long;
ll s[N], si[N], sf[N], a[N];
void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + a[i];
        si[i] = si[i - 1] + a[i] * i;
        sf[i] = sf[i - 1] + a[i] * i * i;
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        ll L = l - 1;
        ll R = r + 1;
        cout << -(sf[r] - sf[l - 1]) + (L + R) * (si[r] - si[l - 1]) - L * R * (s[r] - s[l - 1])
             << "\n";
    }
}

int main()
{
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}