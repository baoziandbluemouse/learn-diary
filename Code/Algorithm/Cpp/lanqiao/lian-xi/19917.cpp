#include <iostream>
using namespace std;
const int N = 1e3 + 10;
using ll = long long;
ll dp[N];
const int mod = 1e9 + 7;
int main()
{
    int n;
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            dp[j] = (dp[j] + dp[j - i]) % mod;
        }
    }
    cout << dp[n] << "\n";
    return 0;
}