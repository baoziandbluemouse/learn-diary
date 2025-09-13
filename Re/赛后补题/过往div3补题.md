---
date: 2025-05-20
---
# 前言
这一篇主要面向vp的**div3**




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











# round-1032

# [Problem - E - Codeforces](https://codeforces.com/contest/2121/problem/E)
首先我们要清楚**l<=r**

按位来判断，可以看出有以下几种情况:

1. 234567与888888,我们对比2与8，相减diff为6,那么这一位很显然就可以贡献为0,并且，如果一个位diff>2,那么**后面的都不用看了，贡献肯定也是为0的**
2. 接着比对，一直到7为止，每位都可以贡献为0，8与7diff为1，我们可以发现这必须贡献一个1
3. 再来一组数字23576和23647,现在可以发现，假如位diff = 0 ，那么对最终结果就会贡献**2**，假如diff = 1 ,那么对最终结果就会贡献**1**
4. 再来一组数字..59..和..60...,这里我们只看两位，可以发现，如果前面一位diff=1，那么就会对后一位产生影响，这里假如是..56..和62..之类的数字，那么就不会有影响，唯独是**9和0**，就会产生一个贡献，那么我们只要在遇到diff为1的位后对后面的位进行**9和0**判断就好了,并且假如**遇到了非9与0的位，那么这个位后面的贡献肯定也都会为0**，如果是**9与0位，那么后面如果再有9与0，也是要加上贡献的，只要到了非9与0位，才会停下**


```cpp
#include <bits/stdc++.h>

using namespace std;

  

void solve()

{

    string a, b;

    cin >> a >> b;

    int n = a.size();

    if (a == b)

    {

        cout << n * 2 << "\n";

        return;

    }

    int res = 0;

    for (int i = 0; i < n; i++)

    {

        if (a[i] == b[i])

        {

            res += 2;

        }

        else if (b[i] - a[i] > 1)

        {

            cout << res << "\n";

            return;

        }

        else

        {

            // a[i]+1=b[i]

            res++;

            for (int j = i + 1; j < n; j++)

            {

                if (a[j] == '9' && b[j] == '0')

                {

                    res++;

                }

                else

                {

                    cout << res << "\n";

                    return;

                }

            }

            break;

        }

    }

    cout << res << "\n";

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

