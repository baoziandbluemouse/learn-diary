---
date: 2025-09-23
---

# [Problem - B - Codeforces](https://codeforces.com/contest/2146/problem/B)

首先，可以看出，假如所有集合加起来，无法包含**1-m**的所有数字，那么明显就是错的。

因此，判断有没有可能有三种情况，首先一种就是所有集合加起来。

接着我们可以直接暴力遍历一遍所有集合来找出剩下两种情况，我们可以发现，假如原本我们加上了所有集合1，2，3，4，5。接着剩下的两种情况，**去掉的集合一定要尽可能少，去掉越少集合，我们能保留所有数字的可能性就越高**，所以根本就不用考虑去掉多个集合的情况，一个集合被去掉就没法保证留下所有数字了，去掉更多肯定更没办法

```cpp
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve()

{

    int n, m;

    cin >> n >> m;

    vector<int> p(m + 1, 0);

    vector<vector<int>> a(n + 1, vector<int>());

    for (int i = 1; i <= n; i++)

    {

        int s;

        cin >> s;

        for (int j = 1; j <= s; j++)

        {

            int x;

            cin >> x;

            a[i].push_back(x);

            p[x]++;

        }

    }

    for (int i = 1; i <= m; i++)

    {

        if (p[i] == 0)

        {

            cout << "NO\n";

            return;

        }

    }

    int tem = 0;

    for (int i = 1; i <= n; i++)

    {

        int ok = 1;

        for (auto &x : a[i])

        {

            p[x]--;

            if (p[x] == 0)

            {

                ok = 0;

                break;

            }

        }

        tem += ok;

        // 复原

        for (auto &x : a[i])

        {

            p[x]++;

        }

    }

    cout << (tem >= 2 ? "YES" : "NO");

    cout << "\n";

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


# [Problem - C - Codeforces](https://codeforces.com/contest/2146/problem/C)

观察Find伪代码，形似二分，不过取mid这个步骤变成了随机取，但其实本质还是一样的，**只要数组是升序的**，就一定能找到数字x，只不过时间复杂度会更高而已。

那么要求一个排列p，有的数字不能被find，有的要被find，假设那个串s为0010010010，那在1左边的数字比1小，右边的数字比1大即可。

如此构造的话，我们可以直接使用下标来构造，例如现在字符为1的下标可以直接为3，6，9，而他们旁边的数字**不能被find**，那就不让他们**升序，而是降序**就好了。比如3左边的数字改为2，1而不是升序的1，2，这样就能保证不被find，也不影响字符为1的下标。

然后我们就会发现，假如有一个不能被find的字符他没有连着，也就是左右都是字符为1的，或是到头了之类的，那他就没法像刚才那样改成降序了，那就构造不出来，输出NO就好了。

```cpp
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve()

{

    int n;

    cin >> n;

    string s;

    cin >> s;

    vector<int> ans;

    for (int i = 0; i < n; i++)

    {

        if (s[i] == '1')

        {

            ans.push_back(i + 1);

        }

        else

        {

            int j = i;

            while (j + 1 < n && s[j + 1] == '0')

            {

                j++;

            }

            if (j - i + 1 == 1)

            {

                cout << "NO\n";

                return;

            }

            for (int k = j; k >= i; k--)

            {

                ans.push_back(k + 1);

            }

            i = j;

        }

    }

    cout << "YES\n";

    for (auto &x : ans)

    {

        cout << x << " ";

    }

    cout << "\n";

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