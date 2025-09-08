#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 40;
int g[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
queue<PII> q;
bool st[N][N];

void bfs(int x1, int y1);
int n;
int main(void)
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &g[i][j]);
        }
    }
    bfs(0, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (g[i][j] == 0 && st[i][j] == false)
            {
                g[i][j] = 2;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", g[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void bfs(int x1, int y1)
{
    q.push({x1, y1});
    st[x1][y1] = true;
    while (q.size())
    {
        PII t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int a = t.first + dx[i];
            int b = t.second + dy[i];
            if (a < 0 || a > n + 1 || b < 0 || b > n + 1)
                continue;
            if (g[a][b] == 1)
                continue;
            if (st[a][b] == true)
                continue;
            st[a][b] = true;
            q.push({a, b});
        }
    }
}