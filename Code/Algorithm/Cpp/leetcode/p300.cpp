
// const int N = 3010;

// class Solution
// {
// public:
//     int dp[N]; // dp[i]表示以第i个数作为结尾，最长递增子序列的长度
//     // int dfs(vector<int>& nums, int x) {
//     //     if (dp[x]) {
//     //         return dp[x];
//     //     }
//     //     int res = 0;
//     //     for (int i = 0; i < x; i++) {
//     //         if (nums[i] < nums[x]) {
//     //             res = max(res, dfs(nums, i) + 1);
//     //         }
//     //     }
//     //     dp[x] = res;
//     //     return res;
//     // }

//     int lengthOfLIS(vector<int> &nums)
//     {
//         int n = nums.size();
//         // int res = -1e9;
//         //  for (int i = 0; i < n; i++) {
//         //      res = max(res, dfs(nums, i));
//         //      // 找到了子问题的最优解，还差最后一个数没加
//         //  }
//         for (int i = 0; i < n; i++)
//         {
//             dp[i] = 1; // 序列一开始只有他自己，算是1
//             for (int j = 0; j < i; j++)
//             {
//                 if (nums[j] < nums[i]) // 可以继承
//                 {
//                     dp[i] = max(dp[i], dp[j] + 1);
//                 }
//             }
//         }
//         int res = -1e9;
//         // 接着遍历dp，找到最长递增子序列，因为最长的不一定是以数组中最后一个数字结尾的
//         for (int i = 0; i < n; i++)
//         {
//             res = max(res, dp[i]);
//         }
//         return res;
//     }
// };