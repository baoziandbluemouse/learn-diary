#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 9;
ll a[N];
bool w[N];
ll prefix[N];
int n;
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> w[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        ll sum = 0;
        ll ess = 0;
        ll minn = 0; // minn默认为0是因为prefix[]中的元素从1开始，而我们要找prefix[l-1]的最小值是可以超出下标的，
                     // 所以绝对会找到prefix[0]，则minn可以取0
        for (int i = 1; i <= n; i++)
        {
            ess += a[i] * w[i];
        }
        for (int i = 1; i <= n; i++)
        {
            prefix[i] = prefix[i - 1] + a[i] * (w[i] ? -1 : 1);
        }
        ll fix = 0;
        for (int i = 1; i <= n; i++) // 求偏移量的最大字段和方法(使用前缀和)
        {
            fix = max(fix, prefix[i] - minn);
            minn = min(minn, prefix[i]);
        }
        ll ans = ess + fix;
        cout << ans << '\n';
    }
}
