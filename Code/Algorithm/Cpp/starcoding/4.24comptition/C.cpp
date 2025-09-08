#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    if (n == k)
    {
        cout << 0 << "\n";
        return;
    }
    int l = -1, r = 1e9 + 1;
    while (l + 1 < r)
    {
        int mid = (r - l) / 2 + l;
        int idx = upper_bound(a.begin(), a.end(), mid) - a.begin() + 1;
        if (n - idx + 1 > k)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << r << "\n";
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