#include <bits/stdc++.h>
using namespace std;
const int N = 10;
using ll = long long;
char g[N][N];
int n, m;
int ans;

void dfs(int x, int y, int f)
{
    if (f >= ans)
        return;
    if (y == m + 1)
    {
        x++;
        y = 1;
    }
    if (x == n + 1)
    {
        ans = f;
        return;
    }
    if (g[x][y] == '.')
    {
        dfs(x, y + 1, f);
        return;
    }
    if (x == 1 || y == 1 || g[x - 1][y] != '#' || g[x][y - 1] != '#' || g[x - 1][y - 1] != '#')
        dfs(x, y + 1, f);
    g[x][y] = '.';
    dfs(x, y + 1, f + 1);
    g[x][y] = '#';
}

void solve()
{
    cin >> n >> m;
    ans = n * m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
        }
    }
    dfs(1, 1, 0);
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}