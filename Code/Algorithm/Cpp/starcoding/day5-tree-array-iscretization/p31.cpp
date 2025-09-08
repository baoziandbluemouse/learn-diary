#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
typedef long long ll;

ll a[N], t[N];
vector<int> X;

int getidx(int x)
{
    return lower_bound(X.begin(), X.end(), x) - X.begin() + 1;
}

int lowbit(int x)
{
    return x & -x;
}

int getsum(int k)
{
    int res = 0;
    for (int i = k; i > 0; i -= lowbit(i))
    {
        res += t[i];
    }
    return res;
}

void update(int k, int x)
{
    for (int i = k; i <= X.size(); i += lowbit(i))
    {
        t[i] += x;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        X.push_back(a[i]);
    }
    // 排序去重
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());

    /*
    树状数组是建立在离散化数组上的
    getsum(X.size())返回当前位置之前的所有元素的和
    getsum(getidx(a[i]))返回当前位置之前小于等于a[i]的元素的个数
    两者相减即为比 a[i] 大的元素的数量。
    */
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += 1ll * getsum(X.size()) - getsum(getidx(a[i]));
        update(getidx(a[i]), 1);
    }
    cout << ans << "\n";
    return 0;
}