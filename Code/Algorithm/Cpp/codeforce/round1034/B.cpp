#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, j, k;
    cin >> n >> j >> k;
    int v = 0, maxx = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        maxx = max(maxx, x);
        if (i == j)
        {
            v = x;
        }
    }
    if (v == maxx)
    {
        cout << "YES\n";
    }
    else if (k != 1)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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