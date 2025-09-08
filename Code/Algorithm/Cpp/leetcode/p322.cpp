// // coins记录了有几种硬币,我们从这些硬币进行组合凑出总金额，有可能凑不出
// // 最后一步是从这几种硬币中选出一个刚好到达总金额的
// // 找出一个组合，这个组合的硬币数量是最少的，并且只要再选一个硬币就能到达总金额
// // 这个组合可能有多种，但硬币最少的只有一个
// // 边界，如果达到总金额就退出了
// const int N = 1e4 + 10;
// int dp[N]; // dp[i]代表总金额为i，到达这个i花费的最少硬币数

// class Solution
// {
// public:
//     // int dfs(vector<int>& coins, int amount) {
//     //     int n = coins.size();
//     //     if (amount < 0) {
//     //         return 1e9;
//     //     }
//     //     int res = 1e9;
//     //     if (dp[amount]) {
//     //         return dp[amount];
//     //     }
//     //     if (amount == 0) {
//     //         return 0;
//     //     }
//     //     for (int i = 0; i < n; i++) {
//     //         res = min(res, dfs(coins, amount - coins[i]) + 1);
//     //     }
//     //     dp[amount] = res;
//     //     return res;
//     // }

//     int coinChange(vector<int> &coins, int amount)
//     {
//         int n = coins.size();
//         // int ans = dfs(coins, amount);
//         memset(dp, 0x3f, sizeof(dp));
//         dp[0] = 0;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = coins[i]; j <= amount; j++)
//             {
//                 dp[j] = min(dp[j], dp[j - coins[i]] + 1);
//             }
//         }
//         return (dp[amount] > 1e9) ? -1 : dp[amount];
//     }
// };