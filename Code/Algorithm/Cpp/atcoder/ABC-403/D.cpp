#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 10;
vector<int> cnt(N, 0);

ll cal(vector<int> &v)
{
    int n = v.size();
    if (n <= 1)
        return 0;
    vector<ll> dp(n + 1, 0);
    // 状态转移方程
    for (int j = 2; j <= n; j++)
    {
        // 注意v的下标由于是从0开始的，所以要减1
        // 于是v真正代表的是第j个元素和j-1个元素
        dp[j] = min(dp[j - 1] + v[j - 1], dp[j - 2] + v[j - 2]);
    }
    return dp[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    if (d == 0)
    {
        // 只需去重
        ll ans = 0;
        for (auto &x : cnt)
        {
            if (x > 1)
                ans += (x - 1);
        }
        cout << ans << "\n";
    }
    else
    {
        // 按模D分出链条，dp分次计算链条，最后累加
        ll ans = 0;
        for (int i = 0; i < d; i++)
        {
            vector<int> v;
            for (int j = i; j < N; j += d)
            {
                v.push_back(cnt[j]);
            }
            ans += cal(v);
        }
        cout << ans << "\n";
    }
    return 0;
}