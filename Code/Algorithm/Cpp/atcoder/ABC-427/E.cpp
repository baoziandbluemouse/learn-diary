#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

string s[N];

struct node
{
    vector<pair<int, int>> vec; // 所有垃圾到T的距离
    int cnt;                    // 操作了几次
};

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int sx, sy;
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == 'T')
            {
                sx = i;
                sy = j;
            }
            if (s[i][j] == '#')
                vec.push_back({i, j});
        }
    }
    if (vec.empty())
    {
        cout << 0 << endl;
        return;
    }
    for (auto &[x, y] : vec)
    {
        x -= sx;
        y -= sy;
    }
    queue<node> q;
    q.push({vec, 0});
    map<vector<pair<int, int>>, int> vis;
    while (!q.empty())
    {
        auto [cur, cnt] = q.front();
        q.pop();
        if (cur.empty())
        {
            cout << cnt << endl;
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            vector<pair<int, int>> ncur;
            int ok = 1;
            for (auto &[x, y] : cur)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx == 0 && ny == 0)
                {
                    ok = 0;
                    break;
                }
                int rx = sx + nx, ry = sy + ny;
                if (rx < 0 || rx >= n || ry < 0 || ry >= m)
                    continue;
                ncur.push_back({nx, ny});
            }
            if (ok == 0)
                continue;
            sort(ncur.begin(), ncur.end());
            if (!vis[ncur])
            {
                vis[ncur] = 1;
                q.push({ncur, cnt + 1});
            }
        }
    }
    cout << -1 << endl;
}

int main()
{
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}