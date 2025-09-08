#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 9;
ll arr[N];
vector<int> X;
struct Q // 存放操作和询问
{
    ll a, b;
} add[N], que[N];

ll getidx(int x)
{
    /*lower_bound下边界 up_bound 上边界
    由于计算机区间习惯左闭右开，所以lower_bound返回第一个等于x的元素（假如有），up_bound返回第一个大于x的元素
    <x, <x, <x, [x, x, x, >x) ,>x
    lower_bound找出数组中第一个大于等于x元素的迭代器,up_bound返回的是第一个严格大于给定值的元素的迭代器。*/
    return lower_bound(X.begin(), X.end(), x) - X.begin() + 1;
    // 返回值范围是[1,X.size()]
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        ll x, w;
        cin >> x >> w;
        X.push_back(x);
        add[i] = {x, w};
    }
    for (int i = 1; i <= q; i++)
    {
        ll l, r;
        cin >> l >> r;
        X.push_back(l);
        X.push_back(r);
        que[i] = {l, r};
    }
    // 排序去重
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());

    for (int i = 1; i <= n; i++)
    {
        ll x = getidx(add[i].a);
        ll w = add[i].b;
        arr[x] += w;
    }

    // 前缀和

    for (int i = 1; i <= X.size(); i++)
    {
        arr[i] += arr[i - 1];
    }

    for (int i = 1; i <= q; i++)
    {
        ll l = getidx(que[i].a);
        ll r = getidx(que[i].b);
        cout << arr[r] - arr[l - 1] << "\n";
    }
    return 0;
}