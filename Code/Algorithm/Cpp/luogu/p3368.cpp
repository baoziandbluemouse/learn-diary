#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
typedef long long ll;
ll a[N], t[N], t2[N];
int n, m;

int lowbit(int x) // 最重要的lowbit
{
    return x & (-x);
}

void update(int x, ll v)
{
    for (int i = x; i <= n; i = i + lowbit(i))
    {
        t[i] += v;
        t2[i] += v * x;
    }
}

ll getsum(int k)
{
    ll sum = 0;
    for (int i = k; i > 0; i = i - lowbit(i))
    {
        sum = sum + t[i] * (k + 1) - t2[i];
    }
    return sum;
}

void solve()
{
    int op, l, r;
    ll v;
    cin >> op;
    if (op == 1)
    {
        cin >> l >> r >> v;
        update(l, v);
        update(r + 1, -v); // 和差分的修改一样
    }
    else
    {
        cin >> r;
        l = r;
        cout << getsum(r) - getsum(l - 1) << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        update(i, a[i]);
        update(i + 1, -a[i]); // 采用差分的形式
    }
    while (m--)
    {
        solve();
    }
    return 0;
}