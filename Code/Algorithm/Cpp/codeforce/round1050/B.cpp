#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        if (t <= y)
        {
            ans++;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int t;
        cin >> t;
        if (t <= x)
        {
            ans++;
        }
    }
    cout << ans << "\n";
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