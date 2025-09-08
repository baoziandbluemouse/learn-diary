#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
using ll = long long;
ll a[N], premin[N];
void solve()
{
    int n;
    ll x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    premin[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        premin[i] = min(premin[i - 1], a[i]);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ll temp = x * (a[i] - premin[i]);
        ans = max(temp, ans);
    }
    cout << ans << "\n";
}

int main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}