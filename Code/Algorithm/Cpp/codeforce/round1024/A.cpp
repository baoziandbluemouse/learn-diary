#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    if (n % p == 0)
    {
        int cnt = n / p;
        if (cnt * q != m)
        {
            cout << "NO" << "\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
    else
    {
        cout << "YES\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}