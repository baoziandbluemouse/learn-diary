#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> pre(n + 1, 0);
    vector<ll> a(n + 1, 0);
    vector<ll> b(k + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> b[i];
    }
    sort(a.begin() + 1, a.end(), greater<ll>());
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }
    sort(b.begin() + 1, b.end());
    ll ans = 0;
    int cur_idx = 0;
    int las_idx = 0;
    for (int i = 1; i <= k; i++)
    {
        int t = b[i];
        if (n - cur_idx < t)
        {
            ans += (pre[n] - pre[cur_idx]);
            cur_idx = n;
            break;
        }
        las_idx = cur_idx;
        cur_idx += t;
        ans += (pre[cur_idx - 1] - pre[las_idx]);
    }
    if (cur_idx != n)
    {
        ans += (pre[n] - pre[cur_idx]);
        cur_idx = n;
    }
    cout << ans << "\n";
}

int main()
{
    int _;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}