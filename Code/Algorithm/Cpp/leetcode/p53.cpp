// // 最大子段和
// // 1.重述问题 求一个数组中和最大的子数组
// // 2.找最后一步 选择了某个数字作为子数组的最后一个数
// // 3.假设最后一步都选同一个数，问题变成什么？
// // 看这个子数组加上最后一个数是否会大于这最后一个数，如果大于就该加上，不大于那么子数组就该以这个数作为起点

// const int M = -1e5 + 9;
// const int N = 1e5 + 9;
// int dp
//     [N]; // dp[i]代表以第i个数作为结尾的最大子段和，可能会继承上一个的，也可能会断开只有他一个
// class Solution
// {
// public:
//     int maxSubArray(vector<int> &nums)
//     {
//         int n = nums.size();
//         dp[0] = nums[0]; // 边界,初始化
//         for (int i = 1; i < n; i++)
//         {
//             dp[i] = max(dp[i - 1] + nums[i], nums[i]);
//         }
//         int ans = M;
//         for (int i = 0; i < n; i++)
//         {
//             ans = max(ans, dp[i]);
//         }
//         return ans;
//     }
// };