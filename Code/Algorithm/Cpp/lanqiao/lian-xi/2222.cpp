#include <bits/stdc++.h>
using namespace std;
const int N = 2100;
using PII = pair<int, int>;
int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int dis[N][N];
unordered_map<int, vector<PII>> mp;

int hashfunc(int x, int y)
{
    return (x - 1) * n + (y - 1);
}

void bfs(int x, int y)
{
    queue<PII> q;
    memset(dis, -1, sizeof(dis));
    dis[x][y] = 0;
    q.push({x, y});
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        // 如果有传送门
        int hash = hashfunc(t.first, t.second);
        if (mp.count(hash))
        {
            for (auto &p : mp[hash])
            {
                int a = p.first;
                int b = p.second;
                if (dis[a][b] == -1)
                {
                    dis[a][b] = dis[t.first][t.second] + 1;
                    q.push({a, b});
                }
            }
        }
        // 普通的走法
        for (int i = 0; i < 4; i++)
        {
            int a = t.first + dx[i];
            int b = t.second + dy[i];
            if (a < 1 || a > n || b < 1 || b > n)
                continue;
            if (dis[a][b] != -1)
                continue;
            dis[a][b] = dis[t.first][t.second] + 1;
            q.push({a, b});
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int t = hashfunc(a, b);
        int p = hashfunc(c, d);
        mp[t].push_back({c, d});
        mp[p].push_back({a, b});
    }
    bfs(n, n);
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum += dis[i][j];
        }
    }
    printf("%.2lf\n", sum / (n * n));
    return 0;
}
