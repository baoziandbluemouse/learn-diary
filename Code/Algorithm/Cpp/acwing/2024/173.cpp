#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 1100;
queue<PII> q;
char g[N][N];
int dist[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;
void bfs(void)
{
    while (q.size())
    {
        PII t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i];
            int y = t.second + dy[i];
            if (x < 1 || x > n || y < 1 || y > m)
                continue;
            if (dist[x][y] >= 0)
                continue;
            dist[x][y] = dist[t.first][t.second] + 1;
            q.push({x, y});
        }
    }
}

int main(void)
{
    scanf("%d%d", &n, &m);
    while (getchar() != '\n')
    {
        continue;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", g[i] + 1);
    }
    memset(dist, -1, sizeof(dist));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (g[i][j] == '1')
            {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    bfs();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
    return 0;
}