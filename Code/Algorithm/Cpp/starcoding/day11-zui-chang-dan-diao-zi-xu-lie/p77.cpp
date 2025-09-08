#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 9;

ll a[N], dp[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (a[j] <= a[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    cout << *max_element(dp + 1, dp + 1 + n) << "\n";
    return 0;
}