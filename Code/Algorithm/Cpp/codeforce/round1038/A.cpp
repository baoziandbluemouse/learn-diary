#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    if (n > 1 && m > 1)
    {
        if (n == 2 && m == 2)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
    else
    {
        cout << "NO\n";
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