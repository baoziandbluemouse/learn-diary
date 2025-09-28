#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n + 1);
    vector<vector<int>> vis(n + 5, vector<int>(m + 5, 0)); // 代表这个是不是黑色的
    vector<vector<int>> cnt(n + 5, vector<int>(m + 5, 0));
    vector<PII> cur;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '#')
            {
                cur.push_back({i, j});
                vis[i][j] = 1;
                ans++;
            }
        }
    }
    while (cur.size())
    {
        vector<PII> temp;
        for (auto &[x, y] : cur)
        {
            // 遍历所有黑色单元格，向四周扩展
            for (int i = 0; i < 4; i++)
            {
                int a = x + dx[i];
                int b = y + dy[i];
                if (a < 0 || a >= n || b < 0 || b >= m)
                {
                    continue;
                }
                if (vis[a][b])
                {
                    continue;
                }
                cnt[a][b]++;
                temp.push_back({a, b});
            }
        }
        cur.clear();
        for (auto &[x, y] : temp)
        {
            if (cnt[x][y] == 1)
            {
                vis[x][y] = 1;
                cur.push_back({x, y});
                ans++;
            }
        }
    }
    cout << ans << "\n";
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