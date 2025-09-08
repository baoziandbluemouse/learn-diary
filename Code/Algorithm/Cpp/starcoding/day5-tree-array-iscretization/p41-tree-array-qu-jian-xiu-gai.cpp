#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
typedef long long ll;
ll a[N], dt[N], dti[N];
int n, q;

int lowbit(int x)
{
    return x & -x;
}

void update(int k, ll x)
{
    for (int i = k; i <= n; i += lowbit(i))
    {
        dt[i] += x;
        dti[i] += k * x;
    }
}

ll getsum(int k)
{
    ll ans = 0;
    for (int i = k; i > 0; i -= lowbit(i))
    {
        ans += (k + 1) * dt[i] - dti[i];
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // 初始化树状数组
    for (int i = 1; i <= n; i++)
    {
        update(i, a[i]);
        update(i + 1, -a[i]);
    }
    // 操作
    for (int i = 1; i <= q; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int l, r;
            ll v;
            cin >> l >> r >> v;
            update(l, v);
            update(r + 1, -v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            ll ans = 0;
            ans = getsum(r) - getsum(l - 1);
            cout << ans << "\n";
        }
    }
    return 0;
}