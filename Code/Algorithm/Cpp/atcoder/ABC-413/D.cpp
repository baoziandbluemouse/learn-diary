#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
ll a[N];
bool cmp(double a, double b)
{
    return abs(a) < abs(b);
}
void solve()
{
    int n;
    cin >> n;
    int ok = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (abs(a[i]) != abs(a[1]))
        {
            ok = 0;
        }
    }
    // 首先判断一下特殊情况，如果全部元素相同,公比要么是1要么是-1，数据要么全正，全负要么交替
    if (ok)
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > 0)
            {
                cnt++;
            }
        }
        if (cnt == n || cnt == 0 || abs(cnt - (n - cnt)) <= 1)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
        return;
    }
    // 接着是一般情况，元素不相同的情况下，要么递增要么递减，数据要么全负要么全正，或者有交替出现的情况
    // 所以用绝对值排序一下就能看出是否是等比数列了
    // 运用等比数列的公式 a(n)^2 = a(n-1)*a(n+1)
    sort(a + 1, a + n + 1, cmp);
    for (int i = 2; i < n; i++)
    {
        if (a[i] * a[i] != a[i - 1] * a[i + 1])
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main()
{
    int _;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}