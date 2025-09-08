#include <bits/stdc++.h>
using namespace std;
const int N = 350;
typedef long long ll;
const ll inf = 0x3f3f3f3f;
// floyd算法，处理多元最短路，时间复杂度O(n^3)，数据范围最多300多
ll d[N][N], n, m, q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    memset(d, 0x3f, sizeof(d));
    for (int i = 1; i <= m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w); // 存储最小的边权
    }

    // 初始化
    for (int i = 1; i <= n; i++)
    {
        d[i][i] = 0; // 自环为0
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << (d[u][v] >= inf ? -1 : d[u][v]);
    }

    return 0;
}