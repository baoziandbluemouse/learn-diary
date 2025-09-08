#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int i = (int)(s[0] - '0');
    int j = (int)(s[2] - '0');
    if (j == 8)
    {
        cout << i + 1 << "-" << 1 << "\n";
    }
    else
    {
        cout << i << "-" << j + 1 << "\n";
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