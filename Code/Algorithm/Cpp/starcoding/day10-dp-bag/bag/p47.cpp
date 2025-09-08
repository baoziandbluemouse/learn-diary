#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505;

ll n, m;
ll dp[2][100005]; // 滚动数组
ll v[N], w[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int y = i & 1;
        for (int j = 0; j <= m; j++)
        {
            if (j >= v[i])
            {
                dp[y][j] = max(dp[y ^ 1][j], dp[y][j - v[i]] + w[i]); // y^1代表另一行，这里可以从同一行转移过来
            }
            else
            {
                dp[y][j] = dp[y ^ 1][j];
            }
        }
    }
    cout << dp[n & 1][m] << "\n";
    return 0;
}