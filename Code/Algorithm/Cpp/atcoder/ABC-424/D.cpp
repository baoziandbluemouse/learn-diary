#include <bits/stdc++.h>
using namespace std;
const int N = 10;
using ll = long long;
char g[N][N];
int n, m;
ll ans = 1e9;

bool check()
{
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1; j <= m - 1; j++)
        {
            if (g[i][j] == '#' && g[i + 1][j] == '#' && g[i][j + 1] == '#' &&
                g[i + 1][j + 1] == '#')
            {
                return false;
            }
        }
    }
    return true;
}

void dfs(ll cnt)
{

    if (check())
    {
        ans = min(ans, cnt);
        return;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1; j <= m - 1; j++)
        {
            if (g[i][j] == '#' && g[i + 1][j] == '#' && g[i][j + 1] == '#' &&
                g[i + 1][j + 1] == '#')
            {
                g[i][j] = '.';
                dfs(cnt + 1);
                g[i][j] = '#';

                g[i + 1][j] = '.';
                dfs(cnt + 1);
                g[i + 1][j] = '#';

                g[i][j + 1] = '.';
                dfs(cnt + 1);
                g[i][j + 1] = '#';

                g[i + 1][j + 1] = '.';
                dfs(cnt + 1);
                g[i + 1][j + 1] = '#';
            }
        }
    }
}

void solve()
{
    ans = 1e9;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
        }
    }
    dfs(0);
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