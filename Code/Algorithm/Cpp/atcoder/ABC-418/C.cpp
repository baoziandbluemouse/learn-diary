#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<ll> a(n + 1, 0);
    ll maxx = -1;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }
    vector<ll> c(maxx + 2, 0);
    vector<ll> prefix(maxx + 2, 0);
    vector<ll> prefix2(maxx + 2, 0);
    for (int i = 1; i <= n; i++)
    {
        c[a[i]]++;
        sum += a[i];
    }
    for (int i = 1; i <= maxx; i++)
    {
        prefix[i] = prefix[i - 1] + c[i];
        prefix2[i] = prefix2[i - 1] + c[i] * i;
    }
    vector<ll> ans(min((ll)1e6, sum) + 2, -1);
    for (int i = 1; i <= maxx; i++)
    {
        ans[i] = prefix2[i - 1] + (i - 1) * (n - prefix[i - 1]);
    }
    while (q--)
    {
        int b;
        cin >> b;
        ll res = (ans[b] == -1) ? ans[b] : ans[b] + 1;
        cout << res << "\n";
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