// const int N = 1050;

// class Solution
// {
//     // 1.重述问题：从第0层/第一层开始爬，每层爬到第n层，求最小花费
//     // 2.找到最后一步:要么爬一层到顶，要么爬两层到顶
//     // 3.去掉最后一步，问题变成了什么:爬到n-1层的最小花费和爬到n-2层的最小花费
//     // （问题规模变小了）（对应之前的最后一步）
//     // 4.边界：dp[0],dp[1]费用都是0
// public:
//     int dp[N]; // 从到第i个台阶为止，爬到顶部的最低费用
//     // int dfs(vector<int>& cost, int x) {
//     //     if (dp[x]) {
//     //         return dp[x];
//     //     }
//     //     int sum = 0;
//     //     if (x == 0 || x == 1) {
//     //         return 0;
//     //     }
//     //     sum = min(dfs(cost, x - 1) + cost[x - 1], dfs(cost, x - 2) + cost[x - 2]);
//     //     dp[x] = sum;
//     //     return sum;
//     // }
//     int minCostClimbingStairs(vector<int> &cost)
//     {
//         int n = cost.size();
//         // int ans = 0;
//         // ans = dfs(cost, n);
//         dp[0] = dp[1] = 0;
//         for (int i = 2; i <= n; i++)
//         {
//             dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
//         }
//         return dp[n];
//     }
// };