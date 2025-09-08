#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x, p;
    cin >> x >> p;
    if (p % x == 0)
    {
        int cnt = p / x - 1;
        int ans = 1 + (2 * cnt);
        cout << ans << "\n";
    }
    else
    {
        int cnt = p;
        for (int i = x; i <= p; i += x)
        {
            cnt--;
        }
        int ans = 2 * cnt;
        cout << ans << "\n";
    }
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