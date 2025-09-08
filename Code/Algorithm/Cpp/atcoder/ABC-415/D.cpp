#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
struct node
{
    ll a, b, z;
    bool operator<(const node &l) const
    {
        if (z != l.z)
        {
            return z < l.z;
        }
        else if (a != l.a)
        {
            return a < l.a;
        }
        else
        {
            return b < l.b;
        }
    }
};
node p[N];
void solve()
{
    ll n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> p[i].a >> p[i].b;
        p[i].z = p[i].a - p[i].b;
    }
    sort(p + 1, p + m + 1);
    ll cur = n, ans = 0;
    for (int i = 1; i <= m; i++)
    {
        if (cur >= p[i].a)
        {
            ll cnt = (cur - p[i].a) / p[i].z + 1;
            ans += cnt;
            cur -= cnt * p[i].z;
        }
    }
    cout << ans << "\n";
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