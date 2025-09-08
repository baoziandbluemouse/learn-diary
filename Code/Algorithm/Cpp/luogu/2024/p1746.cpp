#include <bits/stdc++.h>
using namespace std;
const int N = 1100;
typedef pair<int, int> PII;
char g[N][N];
int dis[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, a, b, c, d;
queue<PII> q;
int bfs(int x1, int y1);
int main(void)
{
    cin >> n;
    cin.ignore();
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", g[i] + 1);
    }
    cin >> a >> b >> c >> d;
    int res = bfs(a, b);
    cout << res << "\n";
    return 0;
}

int bfs(int x1, int y1)
{
    memset(dis, -1, sizeof(int));
    q.push({x1, y1});
    dis[x1][y1] = 0;
    while (q.size())
    {
        PII t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int a = t.first + dx[i];
            int b = t.second + dy[i];
            if (a < 1 || a > n || b < 1 || b > n)
                continue;
            if (g[a][b] != '0')
                continue;
            if (dis[a][b] > 0)
                continue;
            q.push({a, b});
            dis[a][b] = dis[t.first][t.second] + 1;
            if (a == c && b == d)
                return dis[c][d];
        }
    }
    return dis[c][d];
}