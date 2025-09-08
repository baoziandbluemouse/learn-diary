#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 30;
int dis[N][N];
queue<PII> q;
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2, -2, 2, 2, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1, 2, 2, -2, -2};
int bfs(int x1, int y1, int n, int m);
int main(void)
{
    int x2, y2, x3, y3;
    cin >> x2 >> y2 >> x3 >> y3;
    int res1 = bfs(1, 1, x2, y2);
    int res2 = bfs(1, 1, x3, y3);
    cout << res1 << "\n";
    cout << res2 << "\n";
    return 0;
}

int bfs(int x1, int y1, int n, int m)
{
    memset(dis, -1, sizeof(dis));
    q.push({x1, y1});
    dis[x1][y1] = 0;
    while (q.size())
    {
        PII t = q.front();
        q.pop();
        for (int i = 0; i < 12; i++)
        {
            int a = t.first + dx[i];
            int b = t.second + dy[i];
            if (a < 1 || a > 20 || b < 1 || b > 20)
                continue;
            if (dis[a][b] >= 0)
                continue;
            dis[a][b] = dis[t.first][t.second] + 1;
            q.push({a, b});
        }
    }
    return dis[n][m];
}