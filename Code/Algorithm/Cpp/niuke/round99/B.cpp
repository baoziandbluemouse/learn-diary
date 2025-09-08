#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int maxx = -1;
    for (int i = 0; i < s.size(); i++)
    {
        maxx = max(maxx, (int)s[i]);
    }
    cout << maxx << endl;
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