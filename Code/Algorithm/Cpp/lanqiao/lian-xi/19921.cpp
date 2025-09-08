#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2010;
ll dp[N * N]; // dp[i]代表遍历到目前的物品为止，花费了i的体积，所得到的最大价值

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        int v, w, c;
        vector<int> a;
        cin >> v >> w >> c;
        int x = 1;
        while (c >= x)
        {
            a.push_back(x); // 二进制优化
            c -= x;
            x <<= 1;
        }
        if (c)
            a.push_back(c);
        for (auto &i : a) // 跑多次01背包
        {
            for (int j = m; j >= v * i; j--)
            {
                dp[j] = max(dp[j], dp[j - v * i] + w * i);
            }
        }
    }
    cout << dp[m] << "\n";
    return 0;
}