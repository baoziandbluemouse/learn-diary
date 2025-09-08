#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> d(n);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        d[x].push_back(y);
        d[y].push_back(x);
    }
    int leafcnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (d[i].size() == 1)
            leafcnt++;
    }
    if (leafcnt >= n - 1)
    {
        cout << 0 << "\n";
        return;
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int t = 0;
        for (int x : d[i])
        {
            if (d[x].size() == 1)
            {
                t++;
            }
        }
        res = max(res, t);
    }
    cout << leafcnt - res << "\n";
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