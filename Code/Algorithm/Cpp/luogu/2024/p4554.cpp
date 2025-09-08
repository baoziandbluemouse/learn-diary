#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 510;
char g[N][N];
int dis[N][N];
int n, m;
int x, x2, y, y2;
deque<PII> q;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int bfs(int x, int y);
int main(void)
{
    while (cin >> n >> m, n || m)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%s", g[i]);
        }
        memset(dis, -1, sizeof(dis));
        q.clear();
        cin >> x >> y >> x2 >> y2;
        int res = bfs(x, y);
        cout << res << "\n";
    }
    return 0;
}

int bfs(int x, int y)
{
    q.push_back({x, y});
    dis[x][y] = 0;
    while (q.size())
    {
        PII t = q.front();
        q.pop_front();
        char ch = g[t.first][t.second];
        for (int i = 0; i < 4; i++)
        {
            int a = t.first + dx[i];
            int b = t.second + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m)
                continue;
            if (dis[a][b] >= 0)
            {
                continue;
            }
            if (g[a][b] == ch)
            {
                dis[a][b] = dis[t.first][t.second] + 0; // 状态不会变
                q.push_front({a, b});
            }
            if (g[a][b] != ch)
            {
                dis[a][b] = dis[t.first][t.second] + 1; // 状态会增加
                q.push_back({a, b});
            }
            if (a == x2 && b == y2)
            {
                return dis[x2][y2];
            }
        }
    }
    return -1;
}