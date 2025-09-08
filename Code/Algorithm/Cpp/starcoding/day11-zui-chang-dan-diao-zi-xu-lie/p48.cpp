#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 9;
ll a[N];
ll stk[N], top;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        // 找单调栈中最后一个<=a[i]的位置即第一个>a[i]的位置-1，连接
        // top就代表了最长上升子序列的长度
        int pos = upper_bound(stk + 1, stk + 1 + top, a[i]) - stk;
        // upper_bound返回迭代器，-stk则意味着通过减去首地址将迭代器转换为下标

        if (pos == top + 1) // 说明a[i]在栈中是最大的,可以入栈，不用取代
        {
            top++;
        }
        stk[pos] = a[i]; // 如果pos不为top+1,就会发生取代，反之不会
        // 如果发生取代，那么这个a[i]连接前面得到的子序列长度一定不会超过当前top
        // 所以top就不用变了

        ans = max(ans, top);
    }
    cout << ans << "\n";
    return 0;
}
