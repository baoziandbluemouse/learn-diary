#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k, p;
    cin >> n >> k >> p;
    if (n * p < abs(k))
    {
        cout << -1 << "\n";
    }
    else
    {
        k = abs(k);
        cout << (k + p - 1) / p << "\n";
    }
}

int main()
{
    int _;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}