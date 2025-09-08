#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.size() <= 1)
        {
            return s;
        }
        // 人为插入符号实现中心拓展
        string str(s.size() * 2 + 1, '#');
        int idx = 0;
        for (int i = 1; i < str.size(); i += 2)
        {
            str[i] = s[idx++];
        }
        // 进行中心拓展
        vector<int> lens(str.size()); // 记录之前每个点的回文半径
        int right_center = -1;        // 这两个是边界的中心以及右边界，注意这个是右边界不是长度
        int right_bord = -1;
        int max_center = -1;
        int max_len = -1;
        for (int i = 0; i < str.size(); i++)
        {
            int len = (i < right_bord) ? min(lens[2 * right_center - i], right_bord - i) : 1;
            // 假如i包含在边界内，在对称点的回文半径以及到达右边界的半径中选个最小的
            // 假设当前位置为i，对称点为j，则有right_center-j = i - right_center
            // 则j = 2 * right_center - i
            // 如果不在边界内，那就是直接中心拓展即可
            while (i + len < str.size() && i - len > -1)
            {
                if (str[i + len] == str[i - len])
                {
                    len++;
                }
                else
                {
                    break;
                }
            }
            lens[i] = len;
            if (len > max_len)
            {
                max_center = i;
                max_len = len;
            }
            if (i + len > right_bord)
            {
                right_bord = i + len;
                right_center = i;
            }
        }
        string sub = str.substr(max_center - max_len + 1, 2 * max_len - 1);
        string res;
        for (auto &c : sub)
        {
            if (c != '#')
            {
                res.push_back(c);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    string str = s.longestPalindrome("babad");
    cout << str << endl;
    return 0;
}