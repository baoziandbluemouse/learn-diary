#include <bits/stdc++.h>
using namespace std;
// const int N = 100;
const int N = 1e5 + 10;
class Solution
{
public:
    int maximumCostSubstring(string s, string chars, vector<int> &vals)
    {
        // 预处理下权值
        int len = s.size();
        vector<int> dp(N, 0); // dp[i]代表以第i个数字结尾，所得到的最大子段和
        vector<int> a(N, 0);
        for (int i = 0; i < len; i++)
        {
            int pos = chars.find(s[i]);
            if (pos != string::npos)
            {
                a[i] = vals[pos];
            }
            else
            {
                a[i] = s[i] - 'a' + 1;
            }
        }
        dp[0] = a[0];
        for (int i = 1; i < len; i++)
        {
            dp[i] = max(dp[i - 1] + a[i], a[i]);
        }
        int ans = 0;
        for (int i = 0; i < len; i++)
        {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string s1 = "zox";
    string s2 = "zoxr";
    vector<int> a = {2, -5, -4, -5};
    cout << s.maximumCostSubstring(s1, s2, a);
    return 0;
}