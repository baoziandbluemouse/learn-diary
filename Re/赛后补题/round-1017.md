---
date: 2025-04-13
---
# [Problem - B - Codeforces](https://codeforces.com/contest/2094/problem/B)

```cpp
#include <iostream>

#include <cmath>

using namespace std;

  

void solve()

{

    int n, m, l, r, diff;

    cin >> n >> m >> l >> r;

    l = abs(l);

    diff = n-m;

    if(l>=diff)

    {

        l-=diff;

        diff = 0;

    }

    else

    {

        diff-=l;

        l = 0;

    }

    cout << -l << " " << r - diff << "\n";

}

  

int main()

{

    int t;

    cin >> t;

    while (t--)

    {

        solve();

    }

}
```


# [Problem - D - Codeforces](https://codeforces.com/contest/2094/problem/D)


我们发现了可以通过分块出的字符串来判断是否可行，并且只需要得到大小就好了，所以不需要把字符串真分块，只需要得到分块大小就行

```cpp
#include <iostream>

#include <string>

#include <vector>

using namespace std;

  

void solve()

{

    string s;

    string p;

    cin >> p >> s;

    int n = p.size();

    int m = s.size();

    if (m < n || m > 2 * n || s[0] != p[0])

    {

        cout << "NO\n";

        return;

    }

    vector<int> aa, bb;

    // 分块

    int cnt = 1;

    for (int i = 1; i < n; i++)

    {

        if (p[i] != p[i - 1])

        {

            aa.push_back(cnt);

            cnt = 1;

        }

        else

        {

            cnt++;

        }

    }

    aa.push_back(cnt);

    cnt = 1;

    for (int i = 1; i < m; i++)

    {

        if (s[i] != s[i - 1])

        {

            bb.push_back(cnt);

            cnt = 1;

        }

        else

        {

            cnt++;

        }

    }

    bb.push_back(cnt);

    // compare

    if (aa.size() != bb.size())

    {

        cout << "NO\n";

        return;

    }

    else

    {

        for (int i = 0; i < aa.size(); i++)

        {

            if (bb[i] < aa[i] || bb[i] > 2 * aa[i])

            {

                cout << "NO\n";

                return;

            }

        }

    }

    cout << "YES\n";

}

int main()

{

    ios::sync_with_stdio(0);

    cin.tie(0);

    int t;

    cin >> t;

    while (t--)

    {

        solve();

    }

    return 0;

}
```


# [Problem - E - Codeforces](https://codeforces.com/contest/2094/problem/E)

采用了二进制加法，在$O(30)$的复杂度下求出了所有异或值的和,于是只需要$O(30n)$就能判断出最大值


```cpp

#include <iostream>

#include <algorithm>

#include <vector>

using namespace std;

using ll = long long;

  

void solve()

{

    int n;

    cin >> n;

    vector<ll> a;

    vector<ll> cnt(30, 0);

    for (int i = 0; i < n; i++)

    {

        ll x;

        cin >> x;

        a.push_back(x);

        for (int j = 0; j < 30; j++)

        {

            cnt[j] += ((x >> j) & 1);

        }

    }

    ll ans = 0;

  

    for (auto &x : a)

    {

        ll tot = 0;

        for (int i = 0; i < 30; i++)

        {

            bool flag = ((x >> i) & 1);

            if (flag)

            {

                tot += (1ll << i) * (n - cnt[i]);

            }

            else

            {

                tot += (1ll << i) * cnt[i];

            }

        }

        ans = max(ans, tot);

    }

    cout << ans << "\n";

}

  

int main()

{

    ios::sync_with_stdio(0);

    cin.tie(0);

    int t;

    cin >> t;

    while (t--)

    {

        solve();

    }

    return 0;

}
```
