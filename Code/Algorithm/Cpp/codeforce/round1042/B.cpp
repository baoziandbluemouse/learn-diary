#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n == 2)
    {
        cout << -1 << " " << 2 << "\n";
    }
    else if (n % 2 == 0)
    {
        for (int i = 1; i <= n - 1; i++)
        {
            if (i % 2 == 0)
            {
                cout << 3 << " ";
            }
            else
            {
                cout << -1 << " ";
            }
        }
        cout << 2 << "\n";
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                cout << 3 << " ";
            }
            else
            {
                cout << -1 << " ";
            }
        }
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