#include <bits/stdc++.h>
using namespace std;
const int N = 110;
void solve()
{
    int n, a, b = 0, c = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (a == 1 && b == 0)
        {
            b = i;
        }
        if (a == 1)
        {
            c = i;
        }
    }
    cout << c - b << "\n";
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