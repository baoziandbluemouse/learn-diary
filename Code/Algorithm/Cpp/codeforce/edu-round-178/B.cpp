#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    vector<ll> suf(n + 2);
    vector<ll> premax(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = n; i >= 1; i--)
    {
        suf[i] = suf[i + 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        premax[i] = max(premax[i - 1], a[i]);
    }
    for (int k = 1; k <= n; k++)
    {
        ll num = a[n - k + 1];
        if (premax[n - k] > num)
        {
            ll sum = suf[n - k + 1] - num + premax[n - k];
            cout << sum << " ";
        }
        else
        {
            cout << suf[n - k + 1] << " ";
        }
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}