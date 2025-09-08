#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    assert(n >= 1 && n <= 2e4);
    assert(k >= -1e5 && k <= 1e5);
    vector<int> a(n);
    map<int, int> mp;
    mp[0] = -1;
    int sum = 0;
    int minlen = 1e9;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        assert(a[i] >= -1000 && a[i] <= 1000);
    }
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (mp.count(sum - k))
        {
            minlen = min(minlen, i - mp[sum - k]);
        }
        mp[sum] = i;
    }
    if (minlen == 1e9)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << minlen << "\n";
    }
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