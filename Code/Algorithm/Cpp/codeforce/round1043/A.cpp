#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int m;
    cin >> m;
    string t;
    cin >> t;
    string op;
    cin >> op;

    for (int i = 0; i < m; i++)
    {
        if (op[i] == 'D')
        {
            s += t[i];
        }
        else
        {
            s = t[i] + s;
        }
    }
    cout << s << "\n";
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