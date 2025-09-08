#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
typedef pair<int, int> PII;
int n, m;
int g[N][N];
int dis[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int x, int y)
{
    memset(dis, -1, sizeof(dis));
    queue<PII> q;
    q.push({x, y});
    dis[x][y] = 0;
    if (x == n && y == m)
    {
        cout << 0 << "\n";
        return;
    }
    while (q.size())
    {
        PII t = q.front();
        q.pop();
        for (int i = 0; i < 3; i++)
        {
            int a = t.first + dx[i];
            int b = t.second + dy[i];
            if (a < 1 || a > n || b < 1 || b > m)
            {
                continue;
            }
            if (g[a][b])
            {
                continue;
            }
            if (dis[a][b] >= 0)
            {
                continue;
            }
            dis[a][b] = dis[t.first][t.second] + 1;
            q.push({a, b});
            if (a == n && b == m)
            {
                cout << dis[a][b] << "\n";
                return;
            }
        }
    }
    cout << -1 << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
        }
    }
    bfs(1, 1);
    return 0;
}