#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 110;
const int M = 1e4 + 9;
ll dis[N][N];
int pos[M];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> pos[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> dis[i][j];
        }
    }
    // floyd
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    ll ans = 0;
    for (int i = 2; i <= m; i++)
    {
        ans = ans + dis[pos[i - 1]][pos[i]];
    }
    cout << ans << "\n";
    return 0;
}