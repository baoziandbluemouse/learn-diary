#include <iostream>
using namespace std;
using ll = long long;
const int mod = 998244353;
const int N = 1e5 + 10;
int a[N];
ll dp[N][64]; // dp[i][j]代表到第i个数字时，异或和为j时的方案数

int main()
{
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 64; j++)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j ^ a[i]]) % mod;
        }
    }
    cout << dp[n][x] << "\n";
    return 0;
}