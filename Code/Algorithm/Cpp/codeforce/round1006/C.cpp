#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            if ((t | i) == x)
            {
                cout << i << " ";
            }
            else
            {
                cout << x << " ";
            }
        }
        else if (((t | i) & x) == (t | i))
        {
            t |= i;
            cout << i << " ";
        }
        else
        {
            cout << 0 << " ";
        }
    }
    cout << "\n";
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