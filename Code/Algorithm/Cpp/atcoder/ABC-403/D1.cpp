#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int M = 1000000 + 1;

// 计算一条链（计数向量 x）的最小删除操作数
ll calc(const vector<int> &x)
{
    int n = x.size();
    if (n == 0)
        return 0;
    vector<ll> dp(n + 1, 0);
    dp[1] = x[0];
    for (int j = 2; j <= n; ++j)
    {
        ll op1 = dp[j - 1] + x[j - 1]; // 删除当前位置 j
        ll op2 = dp[j - 2] + x[j - 2]; // 保留当前位置 j，则删前一项
        dp[j] = min(op1, op2);
    }
    return dp[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D;
    cin >> N >> D;
    vector<int> cnt(M, 0);
    for (int i = 0, a; i < N; ++i)
    {
        cin >> a;
        cnt[a]++;
    }

    // 特判 D=0：只删重复元素
    if (D == 0)
    {
        ll ans = 0;
        for (int x : cnt)
            if (x > 1)
                ans += (x - 1);
        cout << ans << "\n";
        return 0;
    }

    // D>=1：按模 D 分组，累加每组的 DP 结果
    ll ans = 0;
    for (int i = 0; i < D; ++i)
    {
        vector<int> group;
        for (int j = i; j < M; j += D)
        {
            group.push_back(cnt[j]);
        }
        ans += calc(group);
    }

    cout << ans << "\n";
    return 0;
}