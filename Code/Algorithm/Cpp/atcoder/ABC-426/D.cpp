#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> cnt(2, 0);
    int ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        cnt[s[i] - '0']++;
    }
    // 计算1的最长子串
    int tem = 0;
    int max_tem = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            max_tem = max(tem, max_tem);
            tem = 0;
        }
        else
        {
            tem++;
        }
    }
    if (tem != 0)
    {
        max_tem = max(tem, max_tem);
    }
    if (cnt[1] != 0)
    {
        ans = (cnt[1] - max_tem) * 2 + cnt[0];
    }
    else
    {
        ans = cnt[0];
    }
    // 计算0的最长子串
    tem = 0;
    max_tem = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            max_tem = max(tem, max_tem);
            tem = 0;
        }
        else
        {
            tem++;
        }
    }
    if (tem != 0)
    {
        max_tem = max(tem, max_tem);
    }
    int t = 0;
    if (cnt[0] != 0)
    {
        t = (cnt[0] - max_tem) * 2 + cnt[1];
    }
    else
    {
        t = cnt[1];
    }
    ans = min(ans, t);
    cout << ans << "\n";
}

int main()
{
    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}