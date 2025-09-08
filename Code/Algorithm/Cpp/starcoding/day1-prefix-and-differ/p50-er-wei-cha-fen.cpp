#include <bits/stdc++.h>
using namespace std;
const int N = 1100;
int arr[N][N];
int differ[N][N];
int prefix[N][N];

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
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            differ[i][j] += arr[i][j];     // 这里差分初始化用的原理和下面一样
            differ[i + 1][j] -= arr[i][j]; // 和下面不一样的是因为就只要一个格子变，所以左上右下的坐标都是(i,j)
            differ[i][j + 1] -= arr[i][j];
            differ[i + 1][j + 1] += arr[i][j];
        }
    }
    int a, b, c, d, v;
    while (q--)
    {
        cin >> a >> b >> c >> d >> v;
        differ[a][b] += v;
        differ[a][d + 1] -= v;
        differ[c + 1][b] -= v;
        differ[c + 1][d + 1] += v;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + differ[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}