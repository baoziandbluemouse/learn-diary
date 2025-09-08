#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
typedef long long ll;

ll dp[N];

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
        vector<ll> arr;
        ll x = 1;
        while (s >= x)
        {
            arr.push_back(x);
            s -= x;
            x <<= 1;
        }
        if (s > 0)
        {
            arr.push_back(s);
        }
        for (auto &k : arr)
        {
            for (ll j = m; j >= k * v; j--)
            {
                dp[j] = max(dp[j], dp[j - k * v] + k * w);
            }
        }
    }
    cout << dp[m] << "\n";
    return 0;
}