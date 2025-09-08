
// class Solution
// {
// public:
//     int combinationSum4(vector<int> &nums, int target)
//     {
//         vector<int> dp(target + 1); // dp[i]代表有几种组合可以加到数字i
//         dp[0] = 1;
//         for (int i = 1; i <= target; i++)
//         {
//             for (int j = 0; j < nums.size(); j++)
//             {
//                 if (nums[j] <= i && dp[i - nums[j]] < INT_MAX - dp[i])
//                 {
//                     // 防止整数溢出
//                     dp[i] = dp[i] + dp[i - nums[j]];
//                 }
//             }
//         }
//         return dp[target];
//     }
// };