#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int n;
ll a[N];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 2, a + n);
    ll lst = a[1];
    ll res = 2;
    for (int i = 2; i <= n; i++)
    {
        if (a[n] <= lst * 2)
        {
            cout << res << "\n";
            return;
        }
        if (a[i] <= lst * 2 && a[i + 1] > lst * 2)
        {
            res++;
            lst = a[i];
        }
    }
    cout << -1 << "\n";
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