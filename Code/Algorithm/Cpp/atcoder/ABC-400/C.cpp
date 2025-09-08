#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

ll SQ(ll n)
{
    ll l = 0, r = n + 1;
    while (l + 1 < r)
    {
        ll mid = (l + r) / 2;
        if (mid * mid <= n) // 向下取整，如果没有等于n的，就返回最近小于n的
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    return l;
}

int main()
{
    ll ans = 0;
    ll n;
    cin >> n;
    for (ll i = 2; i <= n; i *= 2)
    {
        ll cnt = sqrtl(n / i); // 向下取整，开根号,由于n很大，所以要开long double，防止精度丢失
        // 第二种解法是手写开方，使用二分法
        cnt = (cnt + 1) / 2; // 得到cnt中所有的奇数
        ans += cnt;
    }
    cout << ans << "\n";
    return 0;
}