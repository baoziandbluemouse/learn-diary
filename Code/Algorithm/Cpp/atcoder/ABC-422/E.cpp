#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
ll x[N], y[N];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= 200; i++)
    {
        int p1 = rand() % n + 1, p2 = rand() % n + 1;
        if (p1 == p2)
            continue;
        /*
            (y-y2)/(x-x2) = (y-y1)/(x-x1)
            (y-y2)*(x-x1) = (y-y1)*(x-x2)
            xy - x1y - xy2 + x1y2 = xy - x2y - xy1 + x2y1
            x(y1-y2) + y(x2-x1) + x1y2 - x2y1 = 0
            a = y1-y2   b = x2-x1  c = x1y2-x2y1
        */
        ll a = y[p2] - y[p1];
        ll b = x[p1] - x[p2];
        ll c = x[p2] * y[p1] - x[p1] * y[p2];
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (a * x[j] + b * y[j] + c == 0)
                cnt++;
        }
        if (cnt > n / 2)
        {
            cout << "Yes" << "\n";
            cout << a << " " << b << " " << c << "\n";
            return;
        }
    }
    cout << "No" << "\n";
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