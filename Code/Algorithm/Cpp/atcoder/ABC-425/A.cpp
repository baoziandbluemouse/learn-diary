#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        ll a = 0;
        if (i % 2 == 0)
        {
            a = i * i * i;
        }
        else
        {
            a = -1 * i * i * i;
        }
        sum += a;
    }
    cout << sum << "\n";
}

int main()
{
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}