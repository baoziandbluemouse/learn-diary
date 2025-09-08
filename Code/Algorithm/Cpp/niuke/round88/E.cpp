#include <iostream>
#include <vector>
#include <climits>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
ll a[N], b[N];
void solve()
{
    int n;
    ll k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(2, LLONG_MIN));
    // dp[i][0]代表了到第i个任务时，当前状态是在表世界所获得的最大收益
    // dp[i][1]代表了到第i个任务时，当前状态是在里世界所获得的最大收益
    dp[0][0] = dp[0][1] = 0;
    dp[1][0] = a[1];
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = max(dp[i - 1][0] + a[i], (dp[i - 1][1] >= k ? dp[i - 1][1] + a[i] - k : LLONG_MIN));
        dp[i][1] = max(dp[i - 1][1] + b[i], (dp[i - 1][0] >= k ? dp[i - 1][0] + b[i] - k : LLONG_MIN));
    }
    cout << max(dp[n][0], dp[n][1]) << "\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}