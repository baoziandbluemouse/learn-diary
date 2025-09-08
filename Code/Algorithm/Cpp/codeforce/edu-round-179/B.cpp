#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 15;
ll a[N];

void init()
{
    a[1] = 1;
    a[2] = 2;
    for (int i = 3; i <= 10; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int w, l, h;
        cin >> w >> l >> h;
        if (w < a[n] || l < a[n] || h < a[n])
        {
            cout << 0;
            continue;
        }
        int p = max(w, max(l, h));
        if (p < a[n] + a[n - 1])
        {
            cout << 0;
            continue;
        }
        cout << 1;
    }
    cout << "\n";
}

int main()
{
    init();
    int _;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
