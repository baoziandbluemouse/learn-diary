#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
bool cmp(ll a, ll b)
{
    return a > b;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n + 1, 0);
    vector<ll> b(n + 1, 0);
    vector<ll> c;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        ans += max(a[i], b[i]);
        c.push_back(min(a[i], b[i]));
    }
    sort(c.begin(), c.end(), cmp);
    for (int i = 0; i < k - 1; i++)
    {
        ans += c[i];
    }
    ans++;
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}