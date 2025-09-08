#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;
const ll p = 1e9 + 7;
class Solution
{
public:
    ll solve(string str, int len, char c)
    {
        ll dp[N]; // dp[i]相当于爬楼梯的状态，代表爬到第i个台阶时，存在的方案数
        memset(dp, 0, sizeof(dp));
        if (c == '2' || c == '3' || c == '4' || c == '5' || c == '6' ||
            c == '8')
        {
            dp[1] = 1;
            dp[2] = 2;
            dp[3] = 4;
            for (int i = 4; i <= len; i++)
            {
                dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % p;
            }
        }
        else
        {
            dp[1] = 1;
            dp[2] = 2;
            dp[3] = 4;
            dp[4] = 8;
            for (int i = 5; i <= len; i++)
            {
                dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4]) % p;
            }
        }
        return dp[len];
    }
    int countTexts(string pressedKeys)
    {
        // 分割字符串
        int len = pressedKeys.size();
        int start = 0;
        vector<ll> a;
        ll ans = 1;
        char c;
        string cur;
        for (int i = 1; i <= len; i++)
        {
            if (i == len || pressedKeys[i] != pressedKeys[start])
            {
                cur = pressedKeys.substr(start, i - start);
                c = cur[0];
                a.push_back(solve(cur, i - start, c));
                start = i;
            }
        }
        // 相乘
        for (auto &i : a)
        {
            ans = (ans * i) % p;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string str = "733999666";
    cout << s.countTexts(str) << "\n";
    return 0;
}