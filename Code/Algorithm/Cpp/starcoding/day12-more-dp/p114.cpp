#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500;
const ll inf = 4e18;
ll a[N], prefix[N], dp[N][N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // 前缀和
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + a[i];
    }

    // 枚举长度k
    for (int len = 2; len <= n; len++)
    {
        // 枚举起点i
        for (int i = 1, j = i + len - 1; j <= n; j++, i++)
        {
            dp[i][j] = inf; // 初始化为无穷
            // 枚举中间点
            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], (dp[i][k] + dp[k + 1][j]) + prefix[j] - prefix[i - 1]);
            }
        }
    }
    cout << dp[1][n] << "\n";
    return 0;
}