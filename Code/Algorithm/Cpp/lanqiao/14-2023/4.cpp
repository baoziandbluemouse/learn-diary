#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int l, r;
ll ans;

void dfs(int dep, ll sum)
{
    if (dep > 2)
    {
        if (sum >= l && sum <= r)
        {
            ans++;
        }
        return;
    }
    for (ll i = l; i <= r; i++)
    {
        if (sum + i > r)
        {
            break;
        }
        else
        {
            dfs(dep + 1, sum + i);
        }
    }
}

void solve()
{
    ans = 0;
    cin >> l >> r;
    dfs(1, 0);
    cout << ans << "\n";
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
}