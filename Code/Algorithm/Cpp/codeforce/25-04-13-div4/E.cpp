#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a;
    vector<ll> cnt(30, 0);
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a.push_back(x);
        for (int j = 0; j < 30; j++)
        {
            cnt[j] += ((x >> j) & 1);
        }
    }
    ll ans = 0;

    for (auto &x : a)
    {
        ll tot = 0;
        for (int i = 0; i < 30; i++)
        {
            bool flag = ((x >> i) & 1);
            if (flag)
            {
                tot += (1ll << i) * (n - cnt[i]);
            }
            else
            {
                tot += (1ll << i) * cnt[i];
            }
        }
        ans = max(ans, tot);
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}