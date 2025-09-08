#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int l, r, d, u;
    cin >> l >> r >> d >> u;
    if (abs(l) == abs(r) && abs(d) == abs(u) && abs(r) == abs(d))
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
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