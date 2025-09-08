#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p = 1e9 + 7;
const int N = 1e3 + 10;
ll c[N][N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;

    // 初始化
    for (int i = 0; i < n; i++)
    {
        c[i][0] = 1ll;
    }
    // 转移方程
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % p;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}