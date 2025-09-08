// // 找出一个数字组合，组合满足和为n，这个组合的乘积最大
// // 最后一步，拆出第k个数
// // 去掉最后一步，则为把n-5拆成k-1个数，使其乘积最大
// const int N = 60;
// int dp[N]; // dp[i]代表拆出数字组合和为i的最大乘积
// class Solution
// {
// public:
//     int dfs(int x)
//     {
//         if (dp[x])
//         {
//             return dp[x];
//         }
//         if (x == 0)
//         {
//             return 1;
//         }
//         int res = 1;
//         for (int i = 1; i < x; i++)
//         {
//             if (x >= i)
//             {
//                 res = max(res, max(i * (x - i), dfs(x - i) * i));
//             }
//         }
//         dp[x] = res;
//         return res;
//     }

//     int integerBreak(int n)
//     {
//         dp[0] = dp[1] = 1;
//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 0; j < i; j++)
//             {
//                 dp[i] = max(dp[i], max(j * (i - j), dp[i - j] * j));
//             }
//         }
//         return dp[n];
//     }
// };