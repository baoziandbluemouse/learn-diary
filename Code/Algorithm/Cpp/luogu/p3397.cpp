#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int differ[N][N];
int arr[N][N];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a, b, c, d;
    while (m--)
    {
        cin >> a >> b >> c >> d;
        differ[a][b] += 1;
        differ[c + 1][d + 1] += 1;
        differ[a][d + 1] -= 1;
        differ[c + 1][b] -= 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + differ[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}