#include <iostream>
#include <cmath>
using namespace std;

void solve()
{
    int n, m, l, r, diff;
    cin >> n >> m >> l >> r;
    l = abs(l);
    diff = n - m;
    if (l >= diff)
    {
        l -= diff;
        diff = 0;
    }
    else
    {
        diff -= l;
        l = 0;
    }
    cout << -l << " " << r - diff << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}