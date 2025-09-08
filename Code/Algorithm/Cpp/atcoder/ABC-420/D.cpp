#include <bits/stdc++.h>
using namespace std;
const int N = 550;
string s[N];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int vis[N][N][2];

int main()
{
    int n, m;
    cin >> n >> m;
    queue<array<int, 4>> q; //(坐标x，坐标y，状态sta，距离dis)
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] = " " + s[i];
        for (int j = 1; j <= m; j++)
        {
            if (s[i][j] == 'S')
            {
                vis[i][j][0] = 1;
                q.push({i, j, 0, 0});
            }
        }
    }
    while (q.size())
    {
        auto [x, y, sta, dis] = q.front();
        if (s[x][y] == 'G')
        {
            cout << dis << "\n";
            return 0;
        }
        q.pop();
        for (int j = 0; j < 4; j++)
        {
            int nx = x + dx[j], ny = y + dy[j], ns = sta;
            if (nx < 1 || nx > n || ny < 1 || ny > m || s[nx][ny] == '#')
                continue;
            if (s[nx][ny] == '?')
                ns ^= 1;
            if (vis[nx][ny][ns])
                continue;
            vis[nx][ny][ns] = 1;
            if (s[nx][ny] != 'o' && s[nx][ny] != 'x')
            {
                q.push({nx, ny, ns, dis + 1});
            }
            if ((s[nx][ny] == 'o' && ns == 0) || (s[nx][ny] == 'x' && ns == 1))
            {
                q.push({nx, ny, ns, dis + 1});
            }
        }
    }

    cout << -1;
    return 0;
}
