#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int n;
int store[N];

// 记忆化搜索想要实现，那么dfs的参数就要尽可能少
// 不应该把没有影响到边界的参数传进去
// 想要剪枝，那么就要把能剪枝的参数写进去
// 所以剪枝和记忆化搜索会有冲突,要么剪枝，要么记忆化

// int mem[N]; // mem[i]代表从第i个店铺时，能获得的最大的价值（选或不选进行比较）

// int dfs(int x) // x代表当前到了哪个店铺
// {
//     if (mem[x])
//     {
//         return mem[x];
//     }
//     int sum = 0;
//     if (x > n)
//     {
//         sum = 0;
//     }
//     else
//     {
//         sum = max(dfs(x + 1), dfs(x + 2) + store[x]);
//     }
//     mem[x] = sum;
//     return sum;
// }
int dp[N]; // dp[i]代表从第i个店铺开始，能获得的最大价值
void solve()
{
    // memset(mem, 0, sizeof(mem));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> store[i];
    }
    // cout << dfs(1) << "\n";
    // 递推
    memset(dp, 0, sizeof(dp));
    for (int i = n; i >= 1; i--)
    {
        dp[i] = max(dp[i + 1], dp[i + 2] + store[i]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}