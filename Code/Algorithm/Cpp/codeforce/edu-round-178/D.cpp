#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 7e6 + 10;
bitset<N> vis;
vector<ll> v;

void init()
{
    for (int i = 2; i <= 7e6; i++)
    {
        if (!vis[i])
        {
            v.push_back(i);
            for (int j = i * 2; j <= 7e6; j += i)
            {
                vis[j] = 1;
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end(), greater<ll>());
    int p = 0;
    ll ans = 0;
    ll x = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= v[p])
        {
            x += a[i] - v[p];
        }
        else
        {
            if (x >= v[p] - a[i])
            {
                x -= v[p] - a[i];
            }
            else
            {
                ans++;
            }
        }
        p++;
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}