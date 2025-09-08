#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 550;
queue<PII> q;
int dis[N][N];
int n, m, a, b, c, d;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(void);

int main(void)
{
    memset(dis, -1, sizeof(dis));
    cin >> n >> m >> a >> b;
    for (int i = 0; i < a; i++)
    {
        int x1, y1;
        scanf("%d%d", &x1, &y1);
        q.push({x1, y1});
        dis[x1][y1] = 0;
    }
    bfs();
    for (int i = 1; i <= b; i++)
    {
        scanf("%d%d", &c, &d);
        printf("%d\n", dis[c][d]);
    }
    return 0;
}

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
            if (dis[x][y] >= 0)
            {
                continue;
            }
            dis[x][y] = dis[t.first][t.second] + 1;
            q.push({x, y});
        }
    }
}