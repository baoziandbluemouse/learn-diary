#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
using ll = long long;
ll a[N], b[N], c[N];
void solve()
{
    ll n, k;
    cin >> n >> k;
    ll now = k; // 剩余容量now
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> c[i];
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    //{离开的时间，离开的人数}
    ll t = 0; // 当前时间
    for (int i = 1; i <= n; i++)
    {
        while (now < c[i])
        {
            t = q.top().first;
            now += q.top().second;
            q.pop();
        }
        t = max(t, a[i]);
        cout << t << "\n";
        now -= c[i];
        q.push({t + b[i], c[i]});
    }
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