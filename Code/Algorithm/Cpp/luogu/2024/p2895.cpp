#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
queue<PII> qt;
const int N = 350;
int g[N][N];   // 记录了陨石砸在地图上的坐标以及时间点,0代表没被砸到,大于0代表被砸到的时间点
int tim[N][N]; // 记录了每个点到起点需要的时间
// 如何判断一个点是否可以走，dis[x][y]>=g[x][y] 说明不能走
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int m;
int bfs(int x1, int y1);
int main(void)
{
    scanf("%d", &m);
    memset(g, 0x3f, sizeof(g));
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
        for (int j = 0; j < 4; j++)
        {
            int p = a + dx[j];
            int q = b + dy[j];
            if (p < 0 || p > 301 || q < 0 || q > 301)
            {
                continue;
            }
            g[p][q] = min(g[p][q], c);
        }
    }
    int res = bfs(0, 0);
    printf("%d\n", res);
    return 0;
}

int bfs(int x1, int y1)
{
    qt.push({x1, y1});
    tim[x1][y1] = 0;
    while (qt.size())
    {
        PII t = qt.front();
        qt.pop();
        for (int i = 0; i < 4; i++)
        {
            int a = t.first + dx[i];
            int b = t.second + dy[i];
            if (a < 0 || b < 0)
            {
                continue;
            }
            if (tim[a][b])
            {
                continue;
            }
            if (tim[t.first][t.second] + 1 >= g[a][b])
            {
                continue;
            }
            tim[a][b] = tim[t.first][t.second] + 1;
            qt.push({a, b});
            if (g[a][b] > 1e9)
            {
                return tim[a][b];
            }
        }
    }
    return -1;
}