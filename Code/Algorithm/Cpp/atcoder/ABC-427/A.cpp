#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    for (int i = 0; i < (s.size() + 1) / 2 - 1; i++)
    {
        cout << s[i];
    }
    for (int i = (s.size() + 1) / 2; i < s.size(); i++)
    {
        cout << s[i];
    }
    cout << "\n";
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