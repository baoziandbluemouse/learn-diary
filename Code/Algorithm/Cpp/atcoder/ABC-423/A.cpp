#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, c;
    cin >> n >> c;
    if (n < 1000 + c)
    {
        cout << 0 << "\n";
        return;
    }
    int maxx = -1;
    for (int i = 1; i <= n / 1000; i++)
    {
        int t = i * 1000;
        if (t + i * c <= n)
        {
            maxx = t;
        }
        else
        {
            cout << maxx << "\n";
            return;
        }
    }
    return;
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