#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
// 二维费用背包，就相当于01背包再加了一维，就是体积和重量的限制
// 那么最开始就是用三维数组来思考，然后我们再优化成二维的
// 这里直接用二维了
int dp[N][N];         // dp[j][l]代表到目前为止，花了j个体积，l个重量，所能获得的最大价值
int a[N], w[N], p[N]; // 体积，重量，价值
int n, m, k;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> w[i] >> p[i];
    }
    // 递推
    for (int i = n; i >= 1; i--)
    {
        for (int j = m; j >= a[i]; j--)
        {
            for (int l = k; l >= w[i]; l--)
            {
                dp[j][l] = max(dp[j][l], dp[j - a[i]][l - w[i]] + p[i]);
            }
        }
    }
    cout << dp[m][k] << "\n";
    return 0;
}