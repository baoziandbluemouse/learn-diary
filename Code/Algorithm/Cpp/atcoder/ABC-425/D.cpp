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
    vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0)); // 代表四周有几个黑
    queue<PII> q;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i][j] == '#')
            {
                q.push({i, j});
                cnt++;
                for (int k = 0; k < 4; k++)
                {
                    int l = i + dx[k];
                    int r = j + dy[k];
                    if (l < 1 || l > n || r < 1 || r > m)
                    {
                        continue;
                    }
                    vis[l][r]++;
                }
            }
        }
    }
    if (cnt == 0)
    {
        cout << 0 << "\n";
        return;
    }
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int a = t.first + dx[i];
            int b = t.second + dy[i];
            if (a < 1 || a > n || b < 1 || b > m)
            {
                continue;
            }
            if (vis[a][b] > 1)
            {
                continue;
            }
            if (s[a][b] == '#')
            {
                continue;
            }
            s[a][b] = '#';
            q.push({a, b});
            for (int k = 0; k < 4; k++)
            {
                int l = a + dx[k];
                int r = b + dy[k];
                if (l < 1 || l > n || r < 1 || r > m)
                {
                    continue;
                }
                vis[l][r]++;
            }
        }
    }
    cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i][j] == '#')
            {
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
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