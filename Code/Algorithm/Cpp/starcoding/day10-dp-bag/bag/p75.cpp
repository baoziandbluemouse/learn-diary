#include <bits/stdc++.h>
using namespace std;
const int N = 109;
typedef long long ll;

ll dp[N * N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        ll s, w, v;
        cin >> s >> w >> v;
        while (s--) // 跑s次01背包
        {
            for (int j = m; j >= v; j--)
            {
                dp[j] = max(dp[j], dp[j - v] + w);
            }
        }
    }
    cout << dp[m] << "\n";
    return 0;
}