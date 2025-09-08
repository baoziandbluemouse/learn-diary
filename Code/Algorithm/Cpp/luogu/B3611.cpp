#include <bits/stdc++.h>
using namespace std;
const int N = 110;
// floyd传递闭包模板
int g[N][N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> g[i][j];
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (g[i][k] && g[k][j])
                {
                    g[i][j] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << g[i][j] << ' ';
        }
        cout << "\n";
    }
    return 0;
}