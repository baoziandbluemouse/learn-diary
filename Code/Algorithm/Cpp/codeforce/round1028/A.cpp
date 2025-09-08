#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b > min(a, c) && d > min(a, c))
    {
        cout << "Flower\n";
    }
    else if (a >= min(b, d) && c >= min(b, d))
    {
        cout << "Gellyfish\n";
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