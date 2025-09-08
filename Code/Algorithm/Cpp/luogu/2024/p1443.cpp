#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 450;
int dis[N][N];
int n, m, x, y;
int tt = 0, hh = 0;
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
PII q[N * N];
void bfs(int x1, int y1);
int main(void)
{
    cin >> n >> m >> x >> y;
    bfs(x, y);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << dis[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
void bfs(int x1, int y1)
{
    memset(dis, -1, sizeof(dis));
    q[0] = {x1, y1};
    dis[x1][y1] = 0;
    while (hh <= tt)
    {
        PII t = q[hh++];
        for (int i = 0; i < 8; i++)
        {
            int a = t.first + dx[i];
            int b = t.second + dy[i];
            if (a < 1 || a > n || b < 1 || b > m)
                continue;
            if (dis[a][b] >= 0)
                continue;
            dis[a][b] = dis[t.first][t.second] + 1;
            q[++tt] = {a, b};
        }
    }
}