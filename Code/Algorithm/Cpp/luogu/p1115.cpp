#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
const int M = -(1e4 + 9);
typedef long long ll;

ll dp[N], a[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll ans = M;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = max(dp[i - 1] + a[i], a[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
    return 0;
}