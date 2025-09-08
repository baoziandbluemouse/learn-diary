#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 10;
ll T, M;
ll dp[110][1010]; // dp[i][j]表示前i个物品，花费了j的时间，所能获得的最大价值
ll t[N], v[N];

void solve()
{
    // 初始化
    for (int i = 0; i <= T; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= M; i++)
    {
        cin >> t[i] >> v[i];
    }
    // 转移方程
    for (int i = 1; i <= M; i++)
    {
        for (int j = 0; j <= T; j++)
        {
            if (j >= t[i])
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t[i]] + v[i]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[M][T] << "\n";
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