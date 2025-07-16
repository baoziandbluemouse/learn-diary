---
date: 2025-04-08
tags:
  - 区间dp
---
# 区间dp

[区间 DP：最长回文子序列【基础算法精讲 22】_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1Gs4y1E7EU/?vd_source=145426a3203c4e7cb072084f20109921)

区间dp与线性dp的区别:

线性dp一般是在前缀/后缀上转移，而区间dp是从小区间转移到大区间


# [516. 最长回文子序列 - 力扣（LeetCode）](https://leetcode.cn/problems/longest-palindromic-subsequence/description/)

思路一:

求S和反转后的S的LCS（[[最长公共子序列]]）

思路二：

【选或不选】从两侧向内缩小规模

假设有一个eacbba

我们从两侧开始看，e和a不相同，那么接下来就只有两种情况，要么不选e，要么不选a

假如不选e，那么左边继续缩小，下一个字母是a，和右边相同，就可以都选，两边同时缩小。

所以**区间dp**的思路和LCS很像

我们定义dp【i】【j】为【i，j】区间中的最长回文子序列的长度

$$dp[i][j] = dp[i+1][j-1]+2 \gets (s[i]=s[j])$$

由内向外的扩张


$$dp[i][j] = max(dp[i+1][j],dp[i][j-1]) \gets (s[i]\ne s[j])$$

要么不选s[i]，要么不选s[j]

边界:

$dp[i][i]=1$ 因为只有一个字母，他自己肯定是回文的

$dp[i+1][i]=0$ 即j小于i时，这肯定是不行的，为0

```cpp
class Solution {

public:

    int longestPalindromeSubseq(string s) {

        // int n = s.size();

        // string rs = s;

        // reverse(rs.begin(), rs.end());

        // vector<vector<int>> dp(n + 1, vector<int>(n + 1));

        // // dp[i][j]代表两个字符串分别遍历到i和j时，所得到的LCS长度

        // dp[0][0] = 0;

        // for (int i = 0; i < n; i++) {

        //     for (int j = 0; j < n; j++) {

        //         if (s[i] == rs[j]) {

        //             dp[i + 1][j + 1] = dp[i][j] + 1;

        //         } else {

        //             dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);

        //         }

        //     }

        // }

        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n));

        //dp[i][j]为[i,j]区间中最长回文子序列的长度

        for (int i = n - 1; i >= 0; i--) {

            dp[i][i] = 1;

            for (int j = i + 1; j < n; j++) {

                if (s[i] == s[j]) {

                    dp[i][j] = dp[i + 1][j - 1] + 2;

                } else {

                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);

                }

            }

        }

        return dp[0][n - 1];

    }

};
```

tips:

- 为何j从i+1开始？

因为我们可以看出当i=j或i<j时，都是属于边界的，无法继续进行递推，所以要从i+1开始

- 如何判断循环该正序或倒序？

我们可以观察状态转移方程，比如现在这个，我们可以看出要求**dp[i]的话，就要知道dp[i+1]的值，那么i就要倒序遍历，从大到小**。

如果要**求dp[j]，就要知道dp[j-1]的值，那么j就要从小到大遍历**，并且因为i<=j属于边界，所以我们要从i+1开始。

# [1039. 多边形三角剖分的最低得分 - 力扣（LeetCode）](https://leetcode.cn/problems/minimum-score-triangulation-of-polygon/description/)

