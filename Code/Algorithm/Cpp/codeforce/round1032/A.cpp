#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, s;
    cin >> n >> s;
    int minn = 1e9, maxx = -1;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        minn = min(x, minn);
        maxx = max(x, maxx);
    }
    int ans = 0;
    if (s == minn || s == maxx)
    {
        ans = maxx - minn;
    }
    else if (s < minn || s > maxx)
    {
        ans = s < minn ? maxx - s : s - minn;
    }
    else
    {
        int dis1 = s - minn;
        int dis2 = maxx - s;
        ans = min(dis1, dis2) * 2 + max(dis1, dis2);
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