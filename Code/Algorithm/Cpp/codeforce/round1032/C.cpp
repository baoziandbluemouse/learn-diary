#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> x(n + 1, 0);
    vector<int> y(m + 1, 0);
    vector<int> a(110, 0);
    vector<vector<int>> g(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int t;
            cin >> t;
            g[i][j] = t;
            a[t]++;
        }
    }
    int maxx = -1;
    for (int i = 1; i <= 100; i++)
    {
        if (a[i])
        {
            maxx = max(maxx, i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (g[i][j] == maxx)
            {
                x[i]++;
                y[j]++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int ans = 0;
            if (g[i][j] == maxx)
            {
                ans = x[i] + y[j] - 1;
            }
            else
            {
                ans = x[i] + y[j];
            }
            if (ans == a[maxx])
            {
                cout << maxx - 1 << "\n";
                return;
            }
        }
    }
    cout << maxx << "\n";
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