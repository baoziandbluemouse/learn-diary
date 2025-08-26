---
date: 2025-05-20
---
# 前言
这一篇主要面向**div3**




# round1006

## [Problem - C - Codeforces](https://codeforces.com/contest/2072/problem/C)

```cpp
#include <bits/stdc++.h>

using namespace std;

  

void solve()

{

    int n, x;

    cin >> n >> x;

    int t = 0;

    for (int i = 0; i < n; i++)

    {

        if (i == n - 1)

        {

            if ((t | i) == x)

            {

                cout << i << " ";

            }

            else

            {

                cout << x << " ";

            }

        }

        else if (((t | i) & x) == (t | i))

        {

            t |= i;

            cout << i << " ";

        }

        else

        {

            cout << 0 << " ";

        }

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
```

## [Problem - D - Codeforces](https://codeforces.com/contest/2072/problem/D)

```cpp
#include <bits/stdc++.h>

using namespace std;

  

void solve()

{

    int n;

    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)

    {

        cin >> a[i];

    }

    int res = 1e8, l, r;

    for (int i = 0; i < n; i++)

    {

        int t1 = 0, t2 = 0;

        for (int j = i; j < n; j++)

        {

            if (a[j] > a[i])

            {

                t2++;

            }

            else if (a[j] < a[i])

            {

                t1++;

            }

            if (res > t2 - t1)

            {

                res = min(res, t2 - t1);

                l = i, r = j;

            }

        }

    }

    cout << l + 1 << " " << r + 1 << "\n";

}

  

int main()

{

    ios::sync_with_stdio(0);

    cin.tie(0);

    int _;

    cin >> _;

    while (_--)

    {

        solve();

    }

    return 0;

}
```

## [Problem - E - Codeforces](https://codeforces.com/contest/2072/problem/E)

```cpp
#include <bits/stdc++.h>

using namespace std;

  

void solve()

{

    int k;

    cin >> k;

    vector<array<int, 2>> ans;

    int x = 0, y = 0;

    for (int i = 450; i >= 2; i--)

    {

        int cnt = i * (i - 1) / 2;

        while (k - cnt >= 0)

        {

            k -= cnt;

            for (int j = 0; j < i; j++)

            {

                ans.push_back({x, y + j});

            }

            x++;

            y += i + 1;

        }

    }

    cout << ans.size() << "\n";

    for (auto &e : ans)

    {

        int a = e[0];

        int b = e[1];

        cout << a << " " << b << "\n";

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

    return 0;

}
```









