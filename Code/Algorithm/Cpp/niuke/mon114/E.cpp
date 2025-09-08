#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int dp[N][4]; // dp[i][j]代表到当前位置为止，选择牌j，花了i种j牌得到的最小花费
int a[4];
int b[N];
int main()
{
    int n = 0;
    for (int i = 1; i <= 3; i++)
    {
        cin >> a[i];
        n += a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    memset(dp, 0x3f, sizeof(dp)); // 初始化
    dp[0][1] = dp[0][2] = dp[0][3] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (b[i] == 1)
        {
            // 选择牌1，并且牌数足够
            if (i <= a[1])
            {
                dp[i][1] = min(dp[i - 1][1], min(dp[i - 1][2], dp[i - 1][3])) + 1;
            }
            dp[i][2] = min(dp[i - 1][1], min(dp[i - 1][2], dp[i - 1][3]));
            dp[i][3] = min(dp[i - 1][1], min(dp[i - 1][2], dp[i - 1][3]));
        }
        else if (b[i] == 2)
        {
            dp[i][2] = min(min(dp[i - 1][1], dp[i - 1][3]), dp[i - 1][2]) + 1;
        }
        else if (b[i] == 3)
        {
            dp[i][3] = min(dp[i - 1][3], min(dp[i - 1][1], dp[i - 1][2])) + 1;
        }
    }
    cout << min(min(dp[n][1], dp[n][2]), dp[n][3]) << "\n";
    return 0;
}