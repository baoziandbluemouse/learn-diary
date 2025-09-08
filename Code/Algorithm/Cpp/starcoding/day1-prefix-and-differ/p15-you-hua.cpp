#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1200;
int g[N][N];
ll prefix[N][N];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + g[i][j];
        }
    }
    int x_l, y_l, x_r, y_r;
    while (q--)
    {
        cin >> x_l >> y_l >> x_r >> y_r;
        ll res = 0;
        res = prefix[x_r][y_r] + prefix[x_l - 1][y_l - 1] - prefix[x_r][y_l - 1] - prefix[x_l - 1][y_r];
        cout << res << '\n';
    }
    return 0;
}