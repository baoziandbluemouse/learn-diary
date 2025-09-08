#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m;
char g[N][N];
bool vis[N][N];
int dis[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void bfs(int x, int y)
{
    deque<pair<int, int>> q;
    memset(dis, 0x3f, sizeof(dis));
    q.push_back({x, y});
    dis[x][y] = 0;
    while (!q.empty())
    {
        auto t = q.front();
        q.pop_front();
        if (vis[t.first][t.second])
        {
            continue;
        }
        vis[t.first][t.second] = true;
        for (int i = 0; i < 4; i++)
        {
            int a = t.first + dx[i];
            int b = t.second + dy[i];
            if (a < 1 || a > n || b < 1 || b > m)
            {
                continue;
            }
            if (g[a][b] == '.')
            {
                if (dis[a][b] > dis[t.first][t.second])
                {
                    dis[a][b] = dis[t.first][t.second];
                    q.push_front({a, b});
                }
            }
            else if (g[a][b] == '#')
            {
                if (dis[a][b] > dis[t.first][t.second] + 1)
                {
                    dis[a][b] = dis[t.first][t.second] + 1;
                    q.push_back({a, b});
                }
                // 前踢能踢两格，再次判断一下
                a = a + dx[i];
                b = b + dy[i];
                if (a < 1 || a > n || b < 1 || b > m)
                {
                    continue;
                }
                if (dis[a][b] > dis[t.first][t.second] + 1)
                {
                    dis[a][b] = dis[t.first][t.second] + 1;
                    q.push_back({a, b});
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
        }
    }
    int stx, sty, edx, edy;
    cin >> stx >> sty >> edx >> edy;
    bfs(stx, sty);
    cout << dis[edx][edy] << "\n";
    return 0;
}