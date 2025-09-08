#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countArrangement(int n)
    {
        vector<int> memo((1 << n), -1); //-1表示没有计算过
        int res = dfs(0, n, memo);
        return res;
    }

    int dfs(int s, int n, vector<int> &memo)
    {
        if (memo[s] != -1)
        {
            return memo[s];
        }
        if (s == (1 << n) - 1)
        {
            //(1<<n)-1代表全集,这意味着s这个集合已经选完了全部数，那么就只有一种优美数列了
            return 1;
        }
        int res = 0;
        int i = __builtin_popcount((unsigned)s) + 1; // 当前要放置的位置
        for (int j = 1; j <= n; j++)
        {
            // 遍历所有数字
            // 这里j-1是因为，我们的s在二进制中的最低位此时不代表0，而是代表1
            // 所以如果要检查数字1，那么就要检查第0位
            // 同理，添加数字时，也要j-1
            if ((s >> (j - 1) & 1) == 0 && (i % j == 0 || j % i == 0))
            {
                res += dfs(s | (1 << (j - 1)), n, memo); // 把数字j添加到S中
            }
        }
        memo[s] = res;
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.countArrangement(1) << endl;
    return 0;
}