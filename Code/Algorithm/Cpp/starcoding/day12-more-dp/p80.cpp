#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 105;
const ll p = 1e6 + 7;
ll a[N];
ll dp[N][N]; // 到第i种花，摆了j盆花，一共有多少种方案

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp[0][0] = 1; // 这样初始化是为了处理放第一种花的所有情况
    /*
    for(int i=1;i<=a[i];i++)   //dp[0][0]就是和这个效果一样，假如用这种方法后面状态转移,i从2开始
    {
        dp[1][i]=1;
    }

    */
    for (int i = 1; i <= n; i++) // 到第i种花为止，且以i结尾（可能没有i）
    {
        for (int j = 0; j <= m; j++) // 一共放了j盆花
        {
            for (int k = 0; k <= a[i] && k <= j; k++) // 有连续的k盆 i类花
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % p;
            }
        }
    }

    cout << dp[n][m] << "\n";
    return 0;
}