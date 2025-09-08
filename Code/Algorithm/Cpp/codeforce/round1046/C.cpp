#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
deque<int> q[N];
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
        q[i].clear();
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        q[a[i]].emplace_back(i);
        if (q[a[i]].size() > a[i])
            q[a[i]].pop_front();
        if (q[a[i]].size() == a[i])
            dp[i] = max(dp[i], dp[q[a[i]].front() - 1] + a[i]);
    }
    cout << dp[n] << "\n";
}

int main()
{
    int _;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}