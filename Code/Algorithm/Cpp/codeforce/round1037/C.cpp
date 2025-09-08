#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll maxx = -1;
    ll st = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxx = max(maxx, a[i]);
        if (i == k - 1)
        {
            st = a[i];
        }
    }
    if (st == maxx)
    {
        cout << "Yes\n";
        return;
    }
    sort(a.begin(), a.end());
    bool flag = false;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == st)
        {
            flag = true;
        }
        if (flag)
        {
            if (a[i + 1] - a[i] > st)
            {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
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