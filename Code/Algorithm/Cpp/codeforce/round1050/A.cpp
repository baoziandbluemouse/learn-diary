#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    int x;
    cin >> x >> n;
    if (n % 2 == 0)
    {
        cout << 0 << "\n";
    }
    else
    {
        cout << x << "\n";
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