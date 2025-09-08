#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt = 0;
    for (auto &x : s)
    {
        if (x == '1')
        {
            cnt++;
        }
    }
    if (cnt <= k)
    {
        cout << "Alice\n";
        return;
    }
    if (k * 2 > n)
    {
        cout << "Alice\n";
    }
    else
    {
        cout << "Bob\n";
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