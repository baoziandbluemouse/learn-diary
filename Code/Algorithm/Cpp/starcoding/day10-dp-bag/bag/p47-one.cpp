#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505;

ll n, m;
ll dp[100005]; // 一维
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
        for (int j = v[i]; j <= m; j++)
        {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    cout << dp[m] << "\n";
    return 0;
}