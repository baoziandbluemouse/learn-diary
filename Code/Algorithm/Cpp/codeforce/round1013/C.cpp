#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
bitset<N> vis;
void solve()
{
    int n;
    cin >> n;
    vis.reset();
    vector<int> a(n + 1);
    for (int i = n, x = 1; i >= 1, x <= n; i--, x++)
    {
        int pos = 0;
        if (i > x)
        {
            pos = n - i + x;
            if (!vis[pos])
            {
                vis[pos] = 1;
                a[i] = x;
            }
            else
            {
                cout << -1 << "\n";
                return;
            }
        }
        else
        {
            pos = x - i;
            if (!vis[pos])
            {
                vis[pos] = 1;
                a[i] = x;
            }
            else
            {
                cout << -1 << "\n";
                return;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
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