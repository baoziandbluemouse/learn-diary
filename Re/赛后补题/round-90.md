---
date: 2025-04-21
---

# [真爱粉Tk（三）](https://ac.nowcoder.com/acm/problem/293107)

```cpp
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()

{

    int n, k;

    cin >> n >> k;

    vector<string> a(n + 1);

    for (int i = 1; i <= n; ++i)

    {

        cin >> a[i];

    }

  

    auto check = [&](ll mid) -> bool

    {

        ll C = 1;

        ll C2 = 0, C25 = 0;

        for (int i = 1; i <= n; i++)

        {

            ll c2 = C2, c25 = C25;

            ll n_c2 = 0, n_c25 = 0;

            for (auto &c : a[i])

            {

                if (c == '2')

                {

                    c2++;

                    n_c2++;

                }

                else if (c == '5')

                {

                    c25 += c2;

                    n_c25 += n_c2;

                }

            }

            if (c25 <= mid)

            {

                C2 = c2;

                C25 = c25;

            }

            else

            {

                if (n_c25 > mid)

                {

                    return 0;

                }

                C++;

                C2 = n_c2;

                C25 = n_c25;

            }

        }

        return C <= k;

    };

  

    ll l = 0, r = 1e15;

    while (l < r)

    {

        ll mid = (l + r) / 2;

        if (check(mid))

        {

            r = mid;

        }

        else

        {

            l = mid + 1;

        }

    }

    cout << l << "\n";

  

    return 0;

}
```

主要可以看看如何处理25子序列个数，这种方法是通用的

我们用一个cnt2 和 cnt25来处理，即一个是完整的子序列，一个是去掉最后一个字母的前缀