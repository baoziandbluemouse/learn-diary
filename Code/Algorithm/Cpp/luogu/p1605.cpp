#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
const int N = 10;
int stx, sty, edx, edy;
int g[N][N];
bool vis[N][N];
int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int ans = 0;

void dfs(int x, int y)
{
    if (x == edx && y == edy)
    {
        ans++;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int a = x + dx[i];
        int b = y + dy[i];
        if (a < 1 || a > n || b < 1 || b > m)
            continue;
        if (g[a][b] == 1)
            continue;
        if (vis[a][b])
            continue;
        vis[a][b] = 1;
        dfs(a, b);
        vis[a][b] = 0;
    }
}
int main()
{
    int t;
    cin >> n >> m >> t;
    cin >> stx >> sty >> edx >> edy;
    for (int i = 1; i <= t; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a][b] = 1;
    }
    vis[stx][sty] = 1;
    dfs(stx, sty);
    cout << ans << "\n";
    return 0;
}