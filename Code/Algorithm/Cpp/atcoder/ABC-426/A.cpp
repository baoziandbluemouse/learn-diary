#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string x, y;
    cin >> x >> y;
    if (x == "Ocelot")
    {
        if (y == x)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    else if (x == "Serval")
    {
        if (y == x)
        {
            cout << "Yes\n";
        }
        else if (y == "Lynx")
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
        }
    }
    else if (x == "Lynx")
    {
        cout << "Yes\n";
    }
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