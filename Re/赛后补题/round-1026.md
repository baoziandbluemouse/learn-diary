---
date: 2025-06-03
---
# [Problem - D - Codeforces](https://codeforces.com/contest/2110/problem/D)


二分**+check使用简单的**线性动态规划


```cpp
#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;

using ll = long long;

const int N = 2e5 + 10;

  

void solve()

{

    int n, m;

    cin >> n >> m;

    vector<int> a(n);

    for (int i = 0; i < n; i++)

    {

        cin >> a[i];

    }

    map<array<int, 2>, int> c;

    for (int i = 0; i < m; i++)

    {

        int x, y, z;

        cin >> x >> y >> z;

        x--, y--;

        if (c.count({x, y}))

        {

            c[{x, y}] = min(c[{x, y}], z);

        }

        else

        {

            c[{x, y}] = z;

        }

    }

    vector<vector<array<int, 2>>> d(n);

    for (auto &e : c)

    {

        auto x = e.first;

        int y = e.second;

        d[x[0]].push_back({x[1], y});

    }

    auto check = [&](ll mid) -> bool

    {

        vector<ll> f(n, -1);

        f[0] = min(mid, ll(a[0]));

        for (int i = 0; i < n; i++)

        {

            for (auto &t : d[i])

            {

                if (t[1] <= f[i])

                {

                    f[t[0]] = max(f[t[0]], min(mid, f[i] + a[t[0]]));

                }

            }

        }

        return f[n - 1] != -1;

    };

    ll l = 0, r = 1e18;

    if (!check(r))

    {

        cout << -1 << "\n";

        return;

    }

    while (l + 1 < r)

    {

        ll mid = l + (r - l) / 2;

        if (check(mid))

        {

            r = mid;

        }

        else

        {

            l = mid;

        }

    }

    cout << r << "\n";

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
```

