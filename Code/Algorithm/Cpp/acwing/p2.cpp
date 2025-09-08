#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;

// int dp[N][N];
int a[N], w[N];
// dp[i][j]代表到从i个物品开始，还剩下j个容积，所能获得的最大价值
// 第二种的dp，是到第i个物品为止，花了j个容积，所能获得的最大价值
// 接下来再用滚动数组优化, 和一维优化
int dp[N];
// int g[N]; // g数组用来存放上一层的结果,避免覆盖
int n, v;

// int dfs(int x, int p) // x代表搜索到第几个物品，p代表剩余了多少容积
// {
//     int sum = 0;
//     if (x > n) // 这里体积要是不够的话会越界，但我们不能直接就剪枝了，所以在下面判断来防止越界
//     {
//         return 0;
//     }
//     if (dp[x][p])
//     {
//         return dp[x][p];
//     }
//
//     if (p <a[x]) // 体积不够，只能不选
//     {
//         sum = dfs(x + 1, p);
//     }
//     else // 体积够，想选或者不想选都可以
//     {
//         sum = max(dfs(x + 1, p), dfs(x + 1, p - a[x]) + w[x]);
//     }
//     dp[x][p] = sum;
//     return sum;
// }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> v;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> w[i];
    }
    // int res = dfs(0, 0);
    // cout << res << "\n";
    // 递推 第一种
    // for (int i = n; i >= 1; i--)
    // {
    //     for (int j = 0; j <= v; j++)
    //     {
    //         if (j < a[i])
    //         {
    //             dp[i][j] = dp[i + 1][j];
    //         }
    //         else
    //         {
    //             dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - a[i]] + w[i]);
    //         }
    //     }
    // }
    // cout << dp[1][v] << "\n";
    // 递推第二种
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j <= v; j++)
    //     {
    //         if (j < a[i])
    //         {
    //             dp[i][j] = dp[i - 1][j];
    //         }
    //         else
    //         {
    //             dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i]] + w[i]);
    //         }
    //     }
    // }
    // cout << dp[n][v] << "\n";
    // 滚动数组
    // for (int i = n; i >= 1; i--)
    // {
    //     for (int j = 0; j <= v; j++)
    //     {
    //         g[j] = dp[j];
    //         if (j >= a[i])
    //         {
    //             g[j] = max(dp[j], dp[j - a[i]] + w[i]);
    //         }
    //     }
    //     memcpy(dp, g, sizeof(dp));
    // }
    for (int i = n; i >= 1; i--)
    {
        for (int j = v; j >= a[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - a[i]] + w[i]); // 当一维优化时，原先的循环顺序就会导致覆盖，所以要倒着来
        }
    }
    cout << dp[v] << "\n";
    return 0;
}