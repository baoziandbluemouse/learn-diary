#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
using PII = pair<int, int>;
ll a[N];
void solve()
{
    int n;
    cin >> n;
    int minn = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[minn] > a[i])
        {
            minn = i;
        }
    }
    vector<PII> b;
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i + 1])
        {
            cnt++;
        }
        else if (a[i] != a[i + 1])
        {
            if (i != (i - cnt + 1))
            {
                b.push_back({i - cnt + 1, i});
            }
            cnt = 1;
        }
    }
    if (n != (n - cnt + 1))
    {
        b.push_back({n - cnt + 1, n});
        cnt = 0;
    }
    ll ans = (n - 1) * a[minn];
    for (auto &e : b)
    {
        int c = e.first;
        int d = e.second;
        ll sum = (c - 1) * a[c] + (n - d) * a[d];
        ans = min(ans, sum);
    }
    cout << ans << "\n";
}

int main()
{
    int _;
    cin >> _;
    while (_--)
    {
        solve();
    }
}
