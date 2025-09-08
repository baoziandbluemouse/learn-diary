#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int k;
    cin >> k;
    if (k == 1)
    {
        cout << 4;
    }
    else
    {
        if (k % 2 == 0)
        {
            for (int i = 1; i <= k / 2; i++)
            {
                cout << 8;
            }
        }
        else
        {
            cout << 4;
            for (int i = 1; i <= k / 2; i++)
            {
                cout << 8;
            }
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