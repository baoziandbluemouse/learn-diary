#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int n;
ll x, y;
void solve()
{
    cin >> x >> y;
    if (x % 2 == 0 && y % 2 == 0)
    {
        cout << y / 2 * x + 2 << '\n';
    }
    else if (x % 2 == 0 && y % 2)
    {
        cout << -1 << '\n';
    }
    else if (x % 2 && y % 2)
    {
        cout << x * y + 1 << '\n';
    }
    else
    {
        if (y % 4)
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << y / 2 * x + 2 << '\n';
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}