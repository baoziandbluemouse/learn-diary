---
date: 2025-06-03
---

# [Problem - B - Codeforces](https://codeforces.com/contest/2116/problem/B)


观察r不难看出，由于是2的幂运算，我们假设有$(2^a+2^b)和(2^c+2^d)$

**只要max(a,b)>max(c,d)，那无论如何这个r都是左边更大。**

如果max(a,b)=max(c,d)，那只要**b>d,就是左，别的就是右。**

那么我们就可以遍历寻找P和Q的**最大值**了。

由于单纯遍历要$O(n^2)$,所以我们用**前缀最大值**来优化。


```cpp
#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;

using ll = long long;

const int N = 1e5 + 5;

ll p[N], q[N];

ll qmi(ll a, ll b)

{

    ll res = 1;

    while (b)

    {

        if (b & 1)

        {

            res = res * a % P;

        }

        a = a * a % P;

        b >>= 1;

    }

    return res;

}

  

void solve()

{

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)

    {

        cin >> p[i];

    }

    for (int i = 0; i < n; i++)

    {

        cin >> q[i];

    }

    ll m1 = 0, m2 = 0, ans = 0;

    for (int i = 0; i < n; i++)

    {

        if (p[m1] < p[i])

            m1 = i;

        if (q[m2] < q[i])

            m2 = i;

        if (p[m1] > q[m2] || (p[m1] == q[m2] && q[i - m1] > p[i - m2]))

        {

            cout << (qmi(2, p[m1]) + qmi(2, q[i - m1])) % P << " ";

        }

        else

        {

            cout << (qmi(2, q[m2]) + qmi(2, p[i - m2])) % P << " ";

        }

    }

    cout << "\n";

    return;

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


# [Problem - C - Codeforces](https://codeforces.com/contest/2116/problem/C)


想要求出最少次数，首先我们要知道怎么个数组替换法。

观察他的数组替换，可以看出最后数组所有元素变为**x=gcd(a1,a2,a3....an)**

接下来看怎么求最少次数

本来**数组中就有x**：那次数就是**数组中不为x的数的个数**

**没有x**的情况：

问题转化为：**在n个数字中，选择最少的数字使得他们的gcd等于x，最少要选多少个数字**。

首先要进行gcd，我们当然是要把数组a中的元素都质因数分解。

可以看出gcd会把两个数a1，a2中并非**共同持有的因子**去掉，这就有点dp的感觉了。

定义状态：$f[i][j]$为前i个数字中，如果gcd为j，最少要选多少个数字

状态转移方程：$$f[i][gcd(j,a[i])]=min(f[i][gcd(j,a[i])],f[i-1][j]+1)$$


```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

int a[N];

  

int gcd(int a, int b)

{

    if (b == 0)

    {

        return a;

    }

    else

    {

        return gcd(b, a % b);

    }

}

  

void solve()

{

    int n;

    cin >> n;

    for (int i = 1; i <= n; i++)

    {

        cin >> a[i];

    }

    int g = a[1];

    for (int i = 2; i <= n; i++)

    {

        g = gcd(g, a[i]);

    }

    int cnt = 0;

    for (int i = 1; i <= n; i++)

    {

        if (a[i] == g)

        {

            cnt++;

        }

    }

    if (cnt)

    {

        cout << n - cnt << "\n";

        return;

    }

    vector<int> f(N, 1e9);

    for (int i = 1; i <= n; i++)

    {

        for (int j = 1; j < N; j++)

        {

            int x = gcd(a[i], j);

            f[x] = min(f[x], f[j] + 1);

        }

        // 初始化,前i个数字，要使gcd为a[i]，只选一个数最好

        f[a[i]] = 1;

    }

    cout << f[g] - 2 + n << "\n";

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

