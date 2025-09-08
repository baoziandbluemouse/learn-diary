#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int l = a / b;
    int r = (a + b - 1) / b;
    if (l == r)
    {
        cout << l << "\n";
    }
    else
    {
        double t = (double)a / b;
        int ans = (t - l) < (r - t) ? l : r;
        cout << ans << "\n";
    }
    return 0;
}