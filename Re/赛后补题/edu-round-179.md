---
date: 2025-06-04
---

# [Problem - D - Codeforces](https://codeforces.com/contest/2111/problem/D)

```cpp
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

  

template <typename T>

bool cmin(T &a, const T &b)

{

    return b < a ? a = b, 1 : 0;

}

template <typename T>

bool cmax(T &a, const T &b)

{

    return b > a ? a = b, 1 : 0;

}

  

void solve()

{

    int n, m;

    cin >> n >> m;

    vector<int> a(m);

    for (int i = 0; i < m; i++)

        cin >> a[i];

    sort(a.begin(), a.end());

    vector<ll> pre(m + 1, 0);

    for (int i = 0; i < m; i++)

        pre[i + 1] = pre[i] + a[i] / 100;

    int res = -1;

    ll rcost = -1e18;

    for (int i = 0; i <= n; i++)

    {

        // i枚举的是分配方式

        // i个学生先选底部的教室，n-i个学生先选顶层的教室

        // 接下去再进行替换

        // 这样子枚举找到最优的一个分配

        // l代表前i个教室的楼层总和

        // r代表后n-i个教室的楼层总和

        // 交替后，r-l2意味着从后n-i个教室移动到前i个教室的移动次数

        // r2-l意味着从前i个教室移动到后n-i个教室的移动次数

        ll l = i == 0 ? 0 : pre[i];

        // last n-i:

        ll r = i == n ? 0 : pre[m] - pre[m - (n - i)];

        ll l2 = i == n ? 0 : pre[n - i];

        ll r2 = i == 0 ? 0 : pre[m] - pre[m - i];

        // l->r2, r->l2

        ll cost1 = r2 - l + (r - l2);

        if (cmax(rcost, cost1))

        {

            res = i;

        }

    }

    for (int i = 0; i < n; i++)

    {

        if (i < res)

        {

            cout << a[i] << " " << a[m - 1 - i] << " ";

            cout << a[i] << " " << a[m - 1 - i] << " ";

            cout << a[i] << " " << a[m - 1 - i] << endl;

        }

        else

        {

            int j = i - res;

            cout << a[m - 1 - j] << " " << a[j] << " ";

            cout << a[m - 1 - j] << " " << a[j] << " ";

            cout << a[m - 1 - j] << " " << a[j] << endl;

        }

    }

}

  

int main()

{

    int _;

    cin >> _;

    while (_--)

    {

        solve();

    }

}
```

