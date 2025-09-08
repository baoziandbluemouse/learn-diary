#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;

// int dp[N][N]; // dp[i][j]代表到从i个物品开始，还剩下j个容积，所能获得的最大价值
int a[N], w[N];
int n, m;
// 一维
int dp[N];
// int dfs(int x, int p)
// {
//     if (dp[x][p])
//     {
//         return dp[x][p];
//     }
//     int sum = 0;
//     if (x > n)
//     {
//         return 0;
//     }
//     if (p < a[x])
//     {
//         sum = dfs(x + 1, p);
//     }
//     else
//     {
//         sum = max(dfs(x + 1, p), dfs(x, p - a[x]) + w[x]);
//     }
//     dp[x][p] = sum;
//     return sum;
// }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> w[i];
    }
    // int res = dfs(1, m);
    // cout << res << "\n";
    // 递推
    // for (int i = n; i >= 1; i--)
    // {
    //     for (int j = 0; j <= m; j++)
    //     {
    //         if (j < a[i])
    //         {
    //             dp[i][j] = dp[i + 1][j];
    //         }
    //         else
    //         {
    //             dp[i][j] = max(dp[i + 1][j], dp[i][j - a[i]] + w[i]);
    //         }
    //     }
    // }
    // cout << dp[1][m] << "\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = a[i]; j <= m; j++)
        {
            dp[j] = max(dp[j], dp[j - a[i]] + w[i]); // 完全背包和01背包是相反的，01背包怕覆盖，完全背包则是需要覆盖
        }
    }
    cout << dp[m] << "\n";
    return 0;
}