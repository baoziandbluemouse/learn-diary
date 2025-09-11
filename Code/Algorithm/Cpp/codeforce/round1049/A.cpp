#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    string p = s;
    sort(p.begin(), p.end());
    for (int i = 0; i < n; i++)
    {
        if (p[i] != s[i])
        {
            ans++;
        }
    }
    cout << ans / 2 << "\n";
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