#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 9;

ll a[N], l[N], r[N];

ll stk[N], top;

int main(void)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    // 求l[],l[]是i左边最近的<a[i]的值的位置
    for (int i = 1; i <= n; i++)
    {
        while (top && a[stk[top]] >= a[i])
        {
            top--;
        }
        // 判断
        if (!top)
        {
            l[i] = 0; // i左边没有任何数比a[i]还小了,能够一直延申
        }
        else
        {
            l[i] = stk[top];
        }
        // 存放
        stk[++top] = i;
    }

    // 初始化
    top = 0;

    // 求r[],r[]是i右边最近的<=a[i]的值的距离
    for (int i = n; i >= 1; i--)
    {
        while (top && a[stk[top]] > a[i])
        {
            top--;
        }
        // 判断
        if (!top)
        {
            r[i] = n + 1; // i右边没有数小于等于i，可以一直延申
        }
        else
        {
            r[i] = stk[top];
        }
        // 存放
        stk[++top] = i;
    }
    // l[i]和r[i]都是开区间
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += a[i] * (r[i] - i) * (i - l[i]);
    }

    cout << ans << '\n';
    return 0;
}