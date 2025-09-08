#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    ll x1_ = -1, x2_ = 1e9, y1_ = -1, y2_ = 1e9;
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        x1_ = max(x1_, x);
        x2_ = min(x2_, x);
        y1_ = max(y1_, y);
        y2_ = min(y2_, y);
    }
    ll s1 = (x1_ - x2_ + 1) / 2;
    ll s2 = (y1_ - y2_ + 1) / 2;
    cout << max(s1, s2) << "\n";
    return 0;
}