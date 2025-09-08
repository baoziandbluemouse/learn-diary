#include <bits/stdc++.h>
using namespace std;
const int N = 110;
typedef pair<int, int> PII;
char g[N][N];
bool st[N][N];
queue<PII> q;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;
int res = 0;
void bfs(int x1, int y1);
int main(void)
{
    scanf("%d%d", &n, &m);
    while (getchar() != '\n')
    {
        continue;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", g[i] + 1);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (g[i][j] != '0' && st[i][j] == false)
            {
                bfs(i, j);
                res++;
            }
        }
    }
    printf("%d\n", res);
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
            if (a < 1 || a > n || b < 1 || b > m)
            {
                continue;
            }
            if (g[a][b] == '0')
            {
                continue;
            }
            if (st[a][b] == true)
            {
                continue;
            }
            q.push({a, b});
            st[a][b] = true;
        }
    }
}