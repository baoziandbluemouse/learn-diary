#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    if (s.size() <= 1)
    {
        cout << s << "\n";
        return 0;
    }
    // 处理字符串
    string exp_s(s.size() * 2 + 1, '#');
    int idx = 0;
    for (int i = 1; i < exp_s.size(); i += 2)
    {
        exp_s[i] = s[idx++];
    }
    // 马拉车算法
    vector<int> p(exp_s.size());       // 记录每个点的回文半径
    int r = -1, c = -1;                // 记录右边界和对应的中心
    int max_len = -1, max_center = -1; // 记录最长的回文串长度以及对应的中心
    for (int i = 0; i < exp_s.size(); i++)
    {
        int cur_r = (i < r) ? min(p[2 * c - i], r - i) : 1;
        while (i + cur_r < exp_s.size() && i - cur_r > -1)
        {
            if (exp_s[i + cur_r] == exp_s[i - cur_r])
            {
                cur_r++;
            }
            else
            {
                break;
            }
        }
        p[i] = cur_r;
        if (i + cur_r > r)
        {
            r = i + cur_r;
            c = i; // 更新边界和中心
        }
        if (i + cur_r - 1 == static_cast<int>(exp_s.size()) - 1 && cur_r >= max_len)
        // 更新最长后缀回文串长度和中心，注意这里是要最长后缀回文串，不是单纯是最长回文串
        {
            max_len = cur_r;
            max_center = i;
        }
    }
    int start = max_center - max_len + 1;
    int length = 2 * max_len - 1;
    string str = exp_s.substr(start, length);
    string ans;
    for (int i = 0; i < start; i++)
    {
        if (exp_s[i] != '#')
        {
            ans += exp_s[i];
        }
    }
    for (auto &c : str)
    {
        if (c != '#')
        {
            ans.push_back(c);
        }
    }
    for (int i = start - 1; i >= 0; i--)
    {
        if (exp_s[i] != '#')
        {
            ans.push_back(exp_s[i]);
        }
    }
    cout << ans << "\n";
    return 0;
}