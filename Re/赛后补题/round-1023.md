---
date: 2025-05-06
---

# [Problem - C - Codeforces](https://codeforces.com/contest/2107/problem/C)

```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

using ll = long long;

  

void solve()

{

    int n;

    ll k;

    cin >> n >> k;

    string s;

    cin >> s;

    vector<ll> a(n);

    for (int i = 0; i < n; i++)

    {

        cin >> a[i];

    }

    ll p = 0;

    bool hitk = false;

    // 先求个最大子段和

    for (int i = 0; i < n; i++)

    {

        if (s[i] == '0')

        {

            p = 0;

        }

        else

        {

            p = max(p, 0ll) + a[i];

            if (p > k)

            {

                cout << "No\n";

                return;

            }

            else if (p == k)

            {

                hitk = true;

            }

        }

    }

    char min_char = s[0];

    for (char c : s)

    {

        if (c < min_char)

        {

            min_char = c;

        }

    }

    if (min_char == '1')

    {

        if (hitk)

        {

            cout << "Yes\n";

            for (auto &x1 : a)

            {

                cout << x1 << " ";

            }

            cout << "\n";

        }

        else

        {

            cout << "No\n";

        }

        return;

    }

  

    for (int i = 0; i < n; i++)

    {

        if (s[i] == '0')

        {

            int l = i - 1, r = i + 1;

            ll t = 0, tl = 0, tr = 0;

            while (l >= 0 && s[l] == '1')

            {

                t += a[l];

                tl = max(tl, t);

                l--;

            }

            t = 0;

            while (r < n && s[r] == '1')

            {

                t += a[r];

                tr = max(tr, t);

                r++;

            }

            cout << "Yes\n";

            for (int j = 0; j < n; j++)

            {

                if (s[j] == '0')

                {

                    cout << (j != i ? ll(-1e18) : (k - tl - tr)) << " ";

                }

                else

                {

                    cout << a[j] << " ";

                }

            }

            cout << "\n";

            return;

        }

    }

}

  

int main()

{

    ios::sync_with_stdio(false);

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
