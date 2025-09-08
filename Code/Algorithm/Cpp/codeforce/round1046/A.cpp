#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int t = max(a, b);
    if (c < a || d < b)
    {
        cout << "NO\n";
        return;
    }
    if (t % 2 == 0)
    {
        int cnt = t / 2 - 1;
        int p = min(a, b);
        if (p > t || p < cnt)
        {
            cout << "NO\n";
            return;
        }
    }
    else
    {
        int cnt = t / 2;
        int p = min(a, b);
        if (p > t || p < cnt)
        {
            cout << "NO\n";
            return;
        }
    }
    c -= a;
    d -= b;
    t = max(c, d);
    if (t % 2 == 0)
    {
        int cnt = t / 2 - 1;
        int p = min(c, d);
        if (p > t || p < cnt)
        {
            cout << "NO\n";
            return;
        }
    }
    else
    {
        int cnt = t / 2;
        int p = min(c, d);
        if (p > t || p < cnt)
        {
            cout << "NO\n";
            return;
        }
    }
    cout<<"YES\n";
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