#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n, m;
vector<ll> X;
ll a[N], t[N];
ll cnt[N], t_new[N]; // cnt记录一个数出现的次数，t_new则是记录一个数在变为0后对逆序对产生的影响
// 注意，树状数组求逆序对必须使用离散化，因为你不能确定桶会不会有数字0

int getidx(ll x)
{
    return lower_bound(X.begin(), X.end(), x) - X.begin() + 1;
}
int lowbit(int x)
{
    return x & (-x);
}

void update(int k, ll x)
{
    for (int i = k; i <= X.size(); i = i + lowbit(i))
    {
        t[i] = t[i] + x;
    }
}

ll getsum(int k)
{
    ll sum = 0;
    for (int i = k; i > 0; i = i - lowbit(i))
    {
        sum = sum + t[i];
    }
    return sum;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        X.push_back(a[i]);
    }
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = ans + getsum(X.size()) - getsum(getidx(a[i]));
        update(getidx(a[i]), 1);
    }
    cout << ans << "\n";
    for (int i = 1; i <= n; i++)
    {
        t_new[a[i]] += i - 1 - cnt[a[i]]; // 这里求的是一个数之前，和他不同的数的个数
        cnt[a[i]]++;
    }
    memset(cnt, 0, sizeof(cnt)); // 注意这里要清空
    for (int i = n; i >= 1; i--)
    {
        t_new[a[i]] -= n - i - cnt[a[i]]; // 这里求的是一个数之后，和他不同的数的个数
        cnt[a[i]]++;
    }
    for (int i = 1; i <= m - 1; i++)
    {
        ans = ans + t_new[m - i];
        cout << ans << "\n";
    }
    return 0;
}