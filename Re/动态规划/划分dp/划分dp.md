---
date: 2025-04-07
tags:
  - 划分dp
  - 动态规划
---
# [2369. 检查数组是否存在有效划分 - 力扣（LeetCode）](https://leetcode.cn/problems/check-if-there-is-a-valid-partition-for-the-array/description/)

如何想出状态定义？

- 如果nums的最后两个数相等，那么去掉这两个数，问题变成剩下n-2个数能否有效划分
- 如果nums的最后三个数相等，那么去掉这三个数，问题变成剩下n-3个数能否有效划分
- 如果nums最后三个数连续递增，去掉，问题变成剩下n-3个数能否有效划分

我们要解决的问题都形如【nums的前i个数能否有效划分】

则可以定义数组dp[i+1]，代表从nums从0-i能否有效划分

此时确定边界dp[0]=true;

根据有效划分的定义，我们可以得出状态转移方程dp[i+1]=true,当

1. dp[i-1] && nums[i] == nums[i-1]
2. dp[i-2] && nums[i] == nums[i-1] == nums[i-2]    (i>1)
3. dp[i-2] && nums[i] == nums[i-1]+1 == nums[i-2]+2  (i>1)

```cpp
class Solution {

public:

    bool validPartition(vector<int>& nums) {

        int n = nums.size();

        vector<bool> dp(n + 1);

        dp[0] = true;

        for (int i = 1; i < n; i++) {

            if (dp[i - 1] && nums[i] == nums[i - 1] ||

                i > 1 && dp[i - 2] &&

                    (nums[i] == nums[i - 1] && nums[i] == nums[i - 2] ||

                     nums[i] == nums[i - 1] + 1 &&

                         nums[i] == nums[i - 2] + 2)) {

                dp[i + 1] = true;

            }

        }

        return dp[n];

    }

};
```





# 分类

划分dp的种类：
- 能否划分
[139. 单词拆分 - 力扣（LeetCode）](https://leetcode.cn/problems/word-break/description/)

- 最优划分
[2707. 字符串中的额外字符 - 力扣（LeetCode）](https://leetcode.cn/problems/extra-characters-in-a-string/description/)

- 约束划分个数