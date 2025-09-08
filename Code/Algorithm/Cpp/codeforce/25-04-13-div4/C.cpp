#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
const int N = 2000;
bitset<N> vis;
int g[850][850];
void solve()
{
    vis.reset();
    int n;
    cin >> n;
    vector<int> a((2 * n + 1), 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> g[i][j];
        }
    }
    int idx = 0;
    for (int i = 1; i < n; i++)
    {
        a[++idx] = g[1][i];
        vis[g[1][i]] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        a[++idx] = g[i][n];
        vis[g[i][n]] = 1;
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        if (vis[i] == 0)
        {
            a[0] = i;
            break;
        }
    }
    for (int i = 0; i <= idx; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}