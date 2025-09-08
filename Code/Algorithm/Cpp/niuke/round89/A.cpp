#include <iostream>
using namespace std;
const int N = 110;
int dp[N]; // dp[i]代表到第i盏灯，最多可以打开几盏
// 选择的话要从i-2，不选就i-1
int main()
{
    int n;
    cin >> n;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = max(dp[i - 2] + 1, dp[i - 1]);
    }
    cout << dp[n] << "\n";
    return 0;
}