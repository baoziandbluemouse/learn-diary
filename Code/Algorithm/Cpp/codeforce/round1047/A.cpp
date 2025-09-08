#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int k, ans;
    cin >> k >> ans;
    for (int i = 1; i <= k; i++)
    {
        ans = ans * 2;
    }
    cout << ans << "\n";
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