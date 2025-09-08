#include <bits/stdc++.h>
using namespace std;

int n, h, m, a, b;
int dp[3005][3005], ans;
// dp[i][j]: 前i个怪物，魔法值为j时，剩余的最大生命值
// 当无法转移时，答案就是此时的i-1

int main()
{
    cin >> n >> h >> m;
    memset(dp, -0x3f, sizeof(dp));
    dp[0][0] = h;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        for (int j = 0; j <= m; j++)
        {
            if (j < b)
            {
                // 如果枚举的法力值没法扣,那就扣生命值
                dp[i][j] = dp[i - 1][j] - a;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j] - a, dp[i - 1][j - b]);
            }
            if (dp[i][j] >= 0)
            {
                ans = i;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}