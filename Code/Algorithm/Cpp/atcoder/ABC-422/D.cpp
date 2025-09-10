#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> ans = {k};
    int mx = 0, mi = 1e9;
    for (int i = 0; i < n; i++)
    {
        vector<int> nxt;
        for (int x : ans)
        {
            nxt.push_back(x / 2);
            nxt.push_back(x - x / 2);
        }
        ans = nxt;
    }
    for (auto x : ans)
    {
        mx = max(mx, x);
        mi = min(mi, x);
    }
    cout << mx - mi << "\n";
    for (auto x : ans)
        cout << x << ' ';
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