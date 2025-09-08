#include <bits/stdc++.h>
using namespace std;
const int N = 2500;
typedef pair<int, int> PII;
int stoptim[N][N];
int tim[N][N];
queue<PII> q;
int n;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool bfs(int x1, int y1);
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(stoptim, 0x3f, sizeof(stoptim));
        memset(tim, -1, sizeof(tim));
        cin >> n;
        int a, b;
        for (int i = 1; i <= n * 2 - 2; i++)
        {
            cin >> a >> b;
            stoptim[a][b] = min(stoptim[a][b], i);
        }
        bool res = bfs(1, 1);
        if (res)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
        while (q.size())
        {
            q.pop();
        }
    }
    return 0;
}
bool bfs(int x1, int y1)
{
    q.push({x1, y1});
    tim[x1][y1] = 0;
    if (x1 == n && y1 == n)
    {
        return true;
    }
    while (q.size())
    {
        PII t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i];
            int y = t.second + dy[i];
            if (x < 1 || x > n || y < 1 || y > n)
            {
                continue;
            }
            if (tim[x][y] >= 0)
            {
                continue;
            }
            if (tim[t.first][t.second] + 1 > stoptim[x][y])
            {
                continue;
            }
            tim[x][y] = tim[t.first][t.second] + 1;
            q.push({x, y});
            if (x == n && y == n)
            {
                return true;
            }
        }
    }
    return false;
}
