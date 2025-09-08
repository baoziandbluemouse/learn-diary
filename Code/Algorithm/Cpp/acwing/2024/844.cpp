#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
#define x first
#define y second
const int N = 110;
int g[N][N];
int n, m;
int dis[N][N]; // 存储每个点到起点的距离
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1}; // 向量数组，四个方向 上右下左
queue<PII> q;             // 存坐标
int bfs(int x1, int y1);
int main(void)
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
        }
    }
    int res = bfs(1, 1);
    cout << res << "\n";
    return 0;
}
int bfs(int x1, int y1)
{                                 // 使用队列模拟广度优先搜索,从起点开始
    memset(dis, -1, sizeof(dis)); // 初始化为-1，-1代表与起点不连通，即是1的位置
    q.push({x1, y1});
    dis[x1][y1] = 0; // 起始点为0
    while (q.size())
    {
        PII t = q.front(); // 取出队头
        q.pop();           // 弹出
        for (int i = 0; i < 4; i++)
        {
            int a = t.x + dx[i]; // 上右下左
            int b = t.y + dy[i];
            if (a < 1 || a > n || b < 1 || b > m) // 越界
                continue;
            if (g[a][b] != 0)
                continue;
            if (dis[a][b] > 0)
                continue;
            q.push({a, b});                // 入队，根据上右下左，满足的条件的进去，然后以上右下左的顺序出队
                                           // 假设入队了一个右的，一个下的，右的先出队就把右的下一个能入队的入队，然后下的再出队
                                           // 这样就保证了广度优先而不是深度优先,即一层一层的出队，而不是一条路走到黑
            dis[a][b] = dis[t.x][t.y] + 1; // 保证了距离是前一个能走的点的距离+1
            if (a == n && b == m)
                return dis[n][m];
        }
    }
    return dis[n][m];
}