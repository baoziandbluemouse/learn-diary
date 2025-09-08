#include <bits/stdc++.h>
using namespace std;
const int N = 1100;
using PII = pair<int, int>;
char g[N][N], ans[N][N];
struct node
{
    int x;
    int y;
    char c;
};
vector<node> dir = {{-1, 0, 'v'}, {0, 1, '<'}, {1, 0, '^'}, {0, -1, '>'}};
bool vis[N][N];
int n, m;
queue<PII> q;

void bfs()
{
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        for (auto &r : dir)
        {
            int x = t.first + r.x;
            int y = t.second + r.y;
            if (x < 1 || x > n || y < 1 || y > m)
                continue;
            if (g[x][y] != '.')
            {
                continue;
            }
            if (vis[x][y])
            {
                continue;
            }
            vis[x][y] = true;
            q.push({x, y});
            ans[x][y] = r.c;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
            if (g[i][j] == 'E')
            {
                q.push({i, j});
                vis[i][j] = true;
            }
        }
    }

    bfs();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (g[i][j] == '.')
            {
                g[i][j] = ans[i][j];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << g[i][j];
        }
        cout << "\n";
    }

    return 0;
}