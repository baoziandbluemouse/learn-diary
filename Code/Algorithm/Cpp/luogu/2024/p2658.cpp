#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 550;
int high[N][N];
int pos[N][N];
int st[N][N];
int n, m, cnt;
int p, q;
int first = 1;
queue<PII> qt;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool isblue_bfs(int x, int y, int mid);

int main(void)
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> high[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> pos[i][j];
            if (pos[i][j] == 1)
            {
                if (first)
                {
                    p = i;
                    q = j;
                    first = 0;
                }
                cnt++;
            }
        }
    }
    int l = -1, r = 1e9 + 1;
    while (l + 1 < r)
    {
        int mid = l + (r - l) / 2;
        if (isblue_bfs(p, q, mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout << r << "\n";
    return 0;
}

bool isblue_bfs(int x, int y, int mid)
{
    memset(st, 0, sizeof(st));
    int res = 0;
    qt.push({x, y});
    if (pos[x][y] == 1)
    {
        res++;
    }
    st[x][y] = 1;
    while (qt.size())
    {
        PII t = qt.front();
        qt.pop();
        for (int i = 0; i < 4; i++)
        {
            int a = t.first + dx[i];
            int b = t.second + dy[i];
            if (a < 1 || a > n || b < 1 || b > m)
            {
                continue;
            }
            if (abs(high[a][b] - high[t.first][t.second]) > mid)
            {
                continue;
            }
            if (st[a][b])
            {
                continue;
            }
            qt.push({a, b});
            st[a][b] = 1;
            if (pos[a][b] == 1)
            {
                res++;
            }
        }
    }
    return res == cnt;
}