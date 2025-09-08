#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 105;
int p[N], g[N][N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    memset(g, 0x3f, sizeof(g));
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> p[i] >> a >> b;
        if (a)
        {
            g[i][a] = g[a][i] = 1;
        }
        if (b)
        {
            g[i][b] = g[b][i] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        g[i][i] = 0;
    }
    // floyd
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    // 枚举每个点
    int ans = inf;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            sum = sum + (p[j] * g[i][j]);
        }
        ans = min(ans, sum);
    }
    cout << ans << "\n";
    return 0;
}