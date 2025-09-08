#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    ll maxx = -1e18;
    ll minn = 1e18;
    int idx1 = 0;
    int idx2 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > maxx)
        {
            maxx = a[i];
            idx1 = i;
        }
        if (a[i] < minn)
        {
            minn = a[i];
            idx2 = i;
        }
    }
    ll ans2 = minn;
    ll ans1 = maxx;
    maxx = -1e18;
    minn = 1e18;
    for (int i = 0; i < n; i++)
    {
        if (i != idx1)
        {
            maxx = max(maxx, a[i]);
        }
        if (i != idx2)
        {
            minn = min(minn, a[i]);
        }
    }
    ans1 = ans1 * maxx;
    ans2 = ans2 * minn;
    cout << max(ans1, ans2) << "\n";
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