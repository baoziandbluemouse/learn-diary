#include <bits/stdc++.h> //双向广搜优化
using namespace std;
const int N = 1100;
typedef pair<int, int> PII;
int n;
char g[N][N];
int dist[N][N];
int vis[N][N];
queue<PII> qt;
int a, b, c, d;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int bfs(void);
int main(void)
{
    cin >> n;
    cin.ignore();
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", g[i] + 1);
    }
    cin >> a >> b >> c >> d;
    int res = bfs();
    cout << res << "\n";
    return 0;
}

int bfs(void)
{
    memset(dist, -1, sizeof(dist)); // dist存（i，j）到起点的距离
    memset(vis, -1, sizeof(vis));   // vis[i][j]表示(i,j)的标记 1是起点开始搜，2是终点开始搜

    dist[a][b] = 0;
    dist[c][d] = 0;
    vis[a][b] = 1, vis[c][d] = 2;
    qt.push({a, b});
    qt.push({c, d});
    while (qt.size())
    {
        PII t = qt.front();
        qt.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i];
            int y = t.second + dy[i];
            if (x < 1 || x > n || y < 1 || y > n)
                continue;
            if (g[x][y] != '0')
                continue;
            if (vis[x][y] + vis[t.first][t.second] == 3) // 说明此时有个交点，起点与终点的搜索相遇
            {
                return dist[x][y] + dist[t.first][t.second] + 1;
            }
            if (dist[x][y] >= 0)
            {
                continue;
            }
            dist[x][y] = dist[t.first][t.second] + 1; // 拓展队头的子节点
            if (vis[x][y] == -1)                      // vis为-1就说明这个点没有被拓展过，那么就根据上一个点的vis进行标记
            {
                vis[x][y] = vis[t.first][t.second];
            }
            qt.push({x, y});
        }
    }
    return -1;
}