#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 30;
// 暴力搜索
//  ll dfs(int n)
//  {
//      if (n == 1)
//      {
//          return 1;
//      }
//      else if (n == 2)
//      {
//          return 2;
//      }
//      else
//      {
//          return dfs(n - 1) + dfs(n - 2);
//      }
//  }
//  记忆化搜索
// ll mem[N];

// ll dfs(int n)
// {
//     if (mem[n])
//     {
//         return mem[n];
//     }
//     ll sum = 0;
//     if (n == 1)
//     {
//         return 1;
//     }
//     else if (n == 2)
//     {
//         return 2;
//     }
//     else
//     {
//         sum = sum + dfs(n - 1) + dfs(n - 2);
//     }
//     mem[n] = sum;
//     return sum;
// }
// 递推
ll dp[N];
int main()
{
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2]; // 状态转移方程
    }
    cout << dp[n] << "\n";
    return 0;
}