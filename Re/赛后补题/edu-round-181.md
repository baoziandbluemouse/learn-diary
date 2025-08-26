---
date: 2025-08-08
---

# [Problem - C - Codeforces](https://codeforces.com/contest/2125/problem/C)

#容斥原理

容斥原理，要我们求好整数，正难则反，找到l到r中所有的不好数，那么不好数一定会包括2，3，5，7这四个个位素数作为因数。

也就是说不好数一定会有x%2=0,x%3=0,x%5=0或是x%7=0

但我们画个图就能发现，直接这样找不好数，会有重叠，因为会有数x%2=0 并且 x%3=0,即x%6=0,也就是说我们要把重叠的再减去

这样我们就能得到一个从0到n的好整数的个数，要l到r的就再用前缀和减一下就好


```cpp
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

  

void solve()

{

    ll l, r;

    cin >> l >> r;

    auto calc = [&](ll n) -> ll

    {

        ll res = n;

        res -= n / 2;

        res -= n / 3;

        res -= n / 5;

        res -= n / 7;

        res += n / 6;

        res += n / 10;

        res += n / 14;

        res += n / 15;

        res += n / 21;

        res += n / 35;

        res -= n / (2 * 3 * 5);

        res -= n / (2 * 3 * 7);

        res -= n / (2 * 5 * 7);

        res -= n / (3 * 5 * 7);

        res += n / (2 * 3 * 5 * 7);

        return res;

    };

    cout << calc(r) - calc(l - 1) << "\n";

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

可以看出，容斥原理就是**奇数重叠的减，偶数重叠的加**


# [Problem - D - Codeforces](https://codeforces.com/contest/2125/problem/D)

```cpp
#include <bits/stdc++.h>

  

using namespace std;

  

using pt = pair<int, int>;

  

const int MOD = 998244353;

  

int add(int x, int y)

{

    x += y;

    if (x >= MOD)

        x -= MOD;

    if (x < 0)

        x += MOD;

    return x;

}

  

int mul(int x, int y)

{

    return x * 1LL * y % MOD;

}

  

int binpow(int x, int y)

{

    int z = 1;

    while (y)

    {

        if (y & 1)

            z = mul(z, x);

        x = mul(x, x);

        y >>= 1;

    }

    return z;

}

  

int divide(int x, int y)

{

    return mul(x, binpow(y, MOD - 2));

}

  

int main()

{

    ios::sync_with_stdio(false);

    cin.tie(0);

    int n, m;

    cin >> n >> m;

    vector<vector<pt>> a(m + 1);

    for (int i = 0; i < n; ++i)

    {

        int l, r, p, q;

        cin >> l >> r >> p >> q;

        a[r].emplace_back(l - 1, divide(p, q));

    }

    vector<int> pr(m + 1);

    pr[0] = 1;

    for (int i = 1; i <= m; ++i)

    {

        int cur = 1;

        for (auto [_, p] : a[i])

            cur = mul(cur, add(1, -p));

        pr[i] = mul(pr[i - 1], cur);

    }

    vector<int> dp(m + 1);

    dp[0] = 1;

    for (int i = 1; i <= m; ++i)

    {

        for (auto [l, p] : a[i])

        {

            int cur = divide(pr[i], pr[l]);

            cur = divide(cur, add(1, -p));

            cur = mul(cur, p);

            dp[i] = add(dp[i], mul(dp[l], cur));

        }

    }

    cout << dp[m] << endl;

}
```

