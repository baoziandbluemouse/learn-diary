#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e5 + 9;

// d数组用于复原dif
ll a[N], dif, d[N];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        dif += d[i];
        a[i] = max(a[i] + dif, 0ll);
        ans += a[i];
        dif -= a[i];
        if (i + k <= n)
            d[i + k] += a[i];
    }
    cout << ans << "\n";
    return 0;
}