#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5010;
int m;
ll c[N][N];

void solve()
{
    int n;
    cin >> n;
    ll ans = 1, sum = 0;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        sum += x;
        ans = ans * c[sum][x] % m;
    }
    cout << ans << "\n";
}

int main()
{
    int _ = 1;
    cin >> _ >> m;
    for (int i = 0; i <= N - 5; i++)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % m;
        }
    }
    while (_--)
    {
        solve();
    }
    return 0;
}