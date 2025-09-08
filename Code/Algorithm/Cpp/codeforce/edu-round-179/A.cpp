#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int x;
    cin >> x;
    bool first = true;
    ll cnt = 0;
    while (x)
    {
        x /= 2;
        if (first)
        {
            cnt += 3;
            first = false;
        }
        else
        {
            cnt += 2;
        }
    }
    cout << cnt << "\n";
}

int main()
{
    int _;
    cin >> _;
    while (_--)
    {
        solve();
    }
}
