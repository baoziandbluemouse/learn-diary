#include <bits/stdc++.h>
using namespace std;
const int N = 550;
typedef pair<int, int> PII;
char g[N][N];
int st[N][N];
queue<PII> q;
int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void bfs(int x1, int y1);

int main(void)
{
    int res = 0;
    scanf("%d%d", &n, &m);
    while (getchar() != '\n')
    {
        continue;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", g[i] + 1);
    }
    bfs(0, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (g[i][j] == '0' && st[i][j] == 0)
            {
                res++;
            }
        }
    }

    cout << res << "\n";
    return 0;
}
void bfs(int x1, int y1)
{
    q.push({x1, y1});
    st[x1][y1] = 1;
    while (q.size())
    {
        PII t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i];
            int y = t.second + dy[i];
            if (x < 0 || x > n + 1 || y < 0 || y > m + 1)
            {
                continue;
            }
            if (st[x][y] == 1)
            {
                continue;
            }
            if (g[x][y] == '*')
            {
                continue;
            }
            st[x][y] = 1;
            q.push({x, y});
        }
    }
}