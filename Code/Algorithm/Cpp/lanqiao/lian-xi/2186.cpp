#include <iostream>
using namespace std;
using ll = long long;

ll dp[2025][15]; // dp[i][j]代表数字和为i时，数字个数为j时的方案数

int main()
{
    dp[0][0] = 1;
    for (int i = 1; i <= 2022; i++) // 枚举选择的数字
    {
        for (int j = 10; j >= 1; j--) // 枚举数字个数
        {
            for (int k = i; k <= 2022; k++)
            {
                dp[k][j] = (dp[k][j] + dp[k - i][j - 1]);
            }
        }
    }
    cout << dp[2022][10] << "\n";
    return 0;
}