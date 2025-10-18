#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int s, a, b, x;
    cin >> s >> a >> b >> x;
    int sum = 0;
    while (x)
    {
        if (x >= a)
        {
            sum += s * a;
            x -= a;
        }
        else
        {
            sum += s * x;
            x = 0;
        }
        if (x >= b)
        {
            x -= b;
        }
        else
        {
            break;
        }
    }
    cout << sum << "\n";
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