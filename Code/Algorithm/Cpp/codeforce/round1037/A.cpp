#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int minn = 1e9;
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        int t = s[i] - '0';
        minn = min(minn, t);
    }
    cout << minn << "\n";
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