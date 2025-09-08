#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;

ll dp[N][2], a[N];

// 计算最大公约数的函数
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    // 输入n和x
    ll n, x;
    cin >> n >> x;

    // 输入数组元素
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    // 动态规划计算最优解
    // dp[i][0]表示第i个元素不修改时的最大GCD和
    // dp[i][1]表示第i个元素修改为a[i]+x时的最大GCD和
    for (int i = 2; i <= n; ++i)
    {
        // 当前元素不修改，对应有前一个元素修改，前一个元素不修改
        dp[i][0] = max(dp[i - 1][0] + gcd(a[i], a[i - 1]), dp[i - 1][1] + gcd(a[i], a[i - 1] + x));
        // 当前元素修改，对应有前一个元素修改，前一个元素不修改
        dp[i][1] = max(dp[i - 1][0] + gcd(a[i] + x, a[i - 1]), dp[i - 1][1] + gcd(a[i] + x, a[i - 1] + x));
    }

    // 输出最大值
    cout << max(dp[n][0], dp[n][1]) << '\n';

    return 0;
}