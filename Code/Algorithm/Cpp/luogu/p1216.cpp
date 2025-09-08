#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int r;
int g[N][N];
// int mem[N][N];        // mem[i][j] 代表从第i层第j个位置开始，所能获得的数字和的最大值
// int dfs(int x, int j) // x代表当前层数 j代表左右
// {
//     if (mem[x][j])
//     {
//         return mem[x][j];
//     }
//     if (x > r || j > x)
//     {
//         return 0;
//     }
//     int sum = 0;
//     sum = max(dfs(x + 1, j) + g[x][j], dfs(x + 1, j + 1) + g[x][j]);
//     // g[x][j]->g[x+1][j] or g[x+1][j+1]
//     mem[x][j] = sum;
//     return sum;
// }
int dp[N]; // dp[j]代表到当前层为止，第j个位置所能获得的最大数字和

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> r;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> g[i][j];
        }
    }
    // cout << dfs(1, 1) << "\n";
    // 递推
    for (int i = r; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[j] = max(dp[j], dp[j + 1]) + g[i][j];
        }
    }
    cout << dp[1] << "\n";
    return 0;
}