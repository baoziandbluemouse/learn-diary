#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int N = 3e5 + 10;
// const int N = 100;
ll a[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<ll> l(n + 1, 0), r(n + 1, n + 1);
    stack<ll> stk;
    // 假设以a[i]为最小值的区间，通过两次单调栈找到他的左右边界l[i],r[i],那么区间就能扩展到l[i]+1,r[i]-1
    // 答案就是a[i]*(r[i]-l[i]-1)
    // 找到左边第一个比他小的数
    for (ll i = 1; i <= n; i++)
    {
        while (stk.size() && a[i] <= a[stk.top()])
        {
            stk.pop();
        }
        if (stk.size())
        {
            l[i] = stk.top();
        }
        stk.push(i);
    }
    while (stk.size())
        stk.pop();
    // 找到右边第一个比他小的数
    for (ll i = n; i >= 1; i--)
    {
        while (stk.size() && a[i] <= a[stk.top()])
        {
            stk.pop();
        }
        if (stk.size())
        {
            r[i] = stk.top();
        }
        stk.push(i);
    }
    // 计算答案
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, a[i] * (r[i] - l[i] - 1));
    }
    cout << ans << "\n";
    return 0;
}