#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 10;
ll T, M;
ll dp[1010]; // 一维dp  dp[j]表示到目前为止，花费了j的时间，所能获得的最大价值
ll t[N], v[N];

void solve()
{
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= M; i++)
    {
        cin >> t[i] >> v[i];
    }
    // 转移方程
    for (int i = 1; i <= M; i++)
    {
        for (int j = T; j >= t[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - t[i]] + v[i]);
        }
    }
    cout << dp[T] << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> T >> M)
    {
        if (T == 0 && M == 0)
            break;
        solve();
    }
    return 0;
}