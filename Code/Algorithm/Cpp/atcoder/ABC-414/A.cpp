#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    int l, r;
    cin >> n >> l >> r;
    int cnt = 0;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        if (x <= l && y >= r)
        {
            cnt++;
        }
    }
    cout << cnt << "\n";
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