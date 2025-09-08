#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1200;
int g[N][N];
ll presum[N][N];

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
            presum[i][j] = presum[i][j - 1] + g[i][j];
        }
    }
    int x_l, y_l, x_r, y_r;
    while (q--)
    {
        cin >> x_l >> y_l >> x_r >> y_r;
        ll res = 0;
        for (int i = x_l; i <= x_r; i++)
        {
            res += presum[i][y_r] - presum[i][y_l - 1];
        }
        cout << res << '\n';
    }
    return 0;
}