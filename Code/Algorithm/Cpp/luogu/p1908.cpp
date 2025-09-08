#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
typedef long long ll;
int a[N];
int t[N]; // 树状数组维护的是一个桶的前缀和 ,桶的下标对应的是X的下标（可以不用开个桶，直接用树状数组加就好了）
// 每次桶中进入一个数前，注意是前，都要进行一次前缀和的查询，查询自然是从结尾到我们要插入的数，所以要用树状数组这种优秀的数据结构
int n;
vector<int> X;

int getnum(int x)
{
    return lower_bound(X.begin(), X.end(), x) - X.begin() + 1;
}

int lowbit(int x)
{
    return x & (-x);
}

void update(int k, int x)
{
    for (int i = k; i <= X.size(); i = i + lowbit(i)) // 注意这里是X.size(),因为桶的下标对应的是X的下标
    {
        t[i] += x;
    }
}

int getsum(int k)
{
    int sum = 0;
    for (int i = k; i > 0; i = i - lowbit(i))
    {
        sum = sum + t[i];
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        X.push_back(a[i]);
    }
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end()); // 排序去重
    ll ans = 0;
    /*
    树状数组是建立在离散化数组上的
    getsum(X.size())返回当前位置之前的所有元素的和
    getsum(getidx(a[i]))返回当前位置之前小于等于a[i]的元素的个数
    两者相减即为比 a[i] 大的元素的数量。
    */
    for (int i = 1; i <= n; i++)
    {
        ans = ans + (ll)getsum(X.size()) - (ll)getsum(getnum(a[i]));
        update(getnum(a[i]), 1); // 桶中进入一个数，桶中所有数的前缀和都要加1（树状数组的单点修改)
    }
    cout << ans << "\n";
    return 0;
}