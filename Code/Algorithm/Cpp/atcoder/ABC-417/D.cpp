#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;
const int N = 1e4 + 10;
int dp[N][1005]; // dp[i][j]代表接收第i个礼物时，心情值为j，最终心情值为多少
int p[N], a[N], b[N], s[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i] >> a[i] >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + b[i];
    }
    for (int i = 1; i <= 1000; i++)
    {
        dp[n + 1][i] = i;
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j <= 1000; j++)
        {
            if (j <= p[i])
            {
                dp[i][j] = dp[i + 1][j + a[i]];
            }
            else
            {
                dp[i][j] = dp[i + 1][max(0, j - b[i])];
            }
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        if (x <= 1000)
        {
            cout << dp[1][x] << "\n";
        }
        else
        {
            int pos = lower_bound(s + 1, s + n + 1, x - 1000) - s;
            if (pos == n + 1)
                cout << x - s[n] << "\n"; // 代表x会一直减少，直到收完所有礼物
            else
                cout << dp[pos + 1][x - s[pos]] << "\n";
        }
    }
    return 0;
}