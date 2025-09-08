#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i];
    }
    vector<int> rl(n), rr(n); // 取过交集的区间
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != -1)
        {
            x += a[i], y += a[i];
        }
        else
        {
            y++;
        }
        int x2 = max(x, l[i]), y2 = min(y, r[i]);
        if (x2 > y2)
        {
            // 空集，过不去
            cout << -1 << "\n";
            return;
        }
        x = x2, y = y2;
        rl[i] = x, rr[i] = y;
    }
    int t = rl[n - 1]; // 反着递推一遍
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] != -1)
        {
            t -= a[i];
        }
        else
        {
            if (t >= (i - 1 >= 0 ? rl[i - 1] : 0) && t <= (i - 1 >= 0 ? rr[i - 1] : 0))
            {
                a[i] = 0;
            }
            else
            {
                a[i] = 1;
            }
            t -= a[i];
        }
    }
    for (auto &xx : a)
    {
        cout << xx << " ";
    }
    cout << "\n";
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