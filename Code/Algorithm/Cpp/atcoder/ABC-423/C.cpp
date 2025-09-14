#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
using ll = long long;
int a[N];
int b[2];
void solve()
{
    int n, r;
    cin >> n >> r;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        b[a[i]]++;
    }
    int cnt_lef = 0;
    int cnt_r = 0;
    for (int i = 1; i <= r; i++)
    {
        if (a[i] == 0)
        {
            break;
        }
        cnt_lef++;
    }
    for (int i = n; i >= r; i--)
    {
        if (a[i] == 0)
        {
            break;
        }
        cnt_r++;
    }
    ll res = n - cnt_lef - cnt_r;
    res += b[1] - cnt_lef - cnt_r;
    cout << res << "\n";
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