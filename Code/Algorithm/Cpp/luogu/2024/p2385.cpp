#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 35;
int dis[N][N];
int g[N][N];
queue<PII> q;
int n, m, m2, m1;
int record_x, record_y;
bool flag = false;
int bfs(int x1, int y1);

int main(void)
{
    scanf("%d%d%d%d", &n, &m, &m2, &m1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &g[i][j]);
            if (g[i][j] == 3)
            {
                record_x = i;
                record_y = j;
            }
        }
    }
    int res1 = bfs(record_x, record_y);
    printf("%d\n", res1);
    return 0;
}

int bfs(int x1, int y1)
{
    int dx[] = {m2, -m2, m1, -m1, m2, -m2, m1, -m1};
    int dy[] = {m1, m1, m2, m2, -m1, -m1, -m2, -m2};
    memset(dis, -1, sizeof(dis));
    q.push({x1, y1});
    dis[x1][y1] = 0;
    while (q.size())
    {
        PII t = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int a = t.first + dx[i];
            int b = t.second + dy[i];
            if (a < 1 || a > n || b < 1 || b > m)
                continue;
            if (g[a][b] == 0 || g[a][b] == 2)
                continue;
            if (dis[a][b] >= 0)
                continue;
            if (g[a][b] == 4)
            {
                flag = true;
            }
            dis[a][b] = dis[t.first][t.second] + 1;
            if (flag)
                return dis[a][b];
            q.push({a, b});
        }
    }
    return -1;
}