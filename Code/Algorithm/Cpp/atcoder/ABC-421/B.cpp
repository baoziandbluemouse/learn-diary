#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 15;
ll x, y;
ll dp[N];
ll rev(ll p)
{
    ll t = 0;
    while (p)
    {
        t = t * 10 + p % 10;
        p /= 10;
    }
    return t;
}

int main()
{
    cin >> x >> y;
    dp[1] = x;
    dp[2] = y;
    for (int i = 3; i <= 10; i++)
    {
        dp[i] = rev(dp[i - 1] + dp[i - 2]);
    }
    cout << dp[10] << "\n";
    return 0;
}