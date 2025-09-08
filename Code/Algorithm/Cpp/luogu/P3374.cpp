#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N], t[N];
int n, m;

int lowbit(int x) // 最重要的lowbit
{
    return x & (-x);
}

void update(int x, int v) // 单点修改
{
    for (int i = x; i <= n; i = i + lowbit(i))
    {
        t[i] += v;
    }
}

int getsum(int k) // 区间求和 ,这里要像前缀和一样求和，最后有个sum(r)-sum(l-1)
{
    int sum = 0;
    for (int i = k; i > 0; i = i - lowbit(i))
    {
        sum += t[i];
    }
    return sum;
}

void solve()
{
    int op, x, y;
    cin >> op >> x >> y;
    if (op == 1)
    {
        update(x, y);
    }
    else
    {
        cout << getsum(y) - getsum(x - 1) << "\n";
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
        update(i, a[i]); // 初始化树状数组
    }
    while (m--)
    {
        solve();
    }
    return 0;
}