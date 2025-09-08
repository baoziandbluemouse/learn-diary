#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 9;

ll a[N];
ll stk[N], top;

bool cmp(const int &a, const int &b)
{
    return a > b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 0;
    while (cin >> a[++n])
        ;
    n--;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        // 找到第一个<a[i]的位置,连接上一个，然后取代这一个
        // 写个比较函数来更改upper
        int pos = upper_bound(stk + 1, stk + top + 1, a[i], cmp) - stk;
        if (pos == top + 1)
        {
            top++;
        }
        stk[pos] = a[i];
        ans = max(ans, top);
    }
    cout << ans << "\n";
    top = 0;
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        // 找到第一个>a[i]的位置,连接上一个，然后取代这一个
        // 这里要大于等于
        int pos = lower_bound(stk + 1, stk + top + 1, a[i]) - stk;
        if (pos == top + 1)
        {
            top++;
        }
        stk[pos] = a[i];
        ans = max(ans, top);
    }
    cout << ans << "\n";
    return 0;
}