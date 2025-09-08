#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int n, m;
char s[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> s[i][j];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i][j] == '.')
                continue;
            int cnt = 0;
            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx < 1 || nx > n || ny < 1 || ny > m || s[nx][ny] == '.')
                    continue;
                cnt++;
            }
            if (cnt != 2 && cnt != 4)
            {
                cout << "No";
                return;
            }
        }
    }
    cout << "Yes";
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