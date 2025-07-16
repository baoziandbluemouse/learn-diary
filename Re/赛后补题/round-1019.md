---
date: 2025-04-23
---


# [Problem - C - Codeforces](https://codeforces.com/contest/2103/problem/C)

```cpp
#include <bits/stdc++.h>

using namespace std;

  

bool check_prefix_and_middle(vector<int> a, int n)

{

    // 构造后缀和，以及从i到n之间所有suf值的最小值

    vector<int> suf(n + 10, 0);

    vector<int> minsuf(n + 10, 0);

    suf[n] = minsuf[n] = a[n];

    for (int i = n - 1; i >= 1; i--)

    {

        suf[i] = suf[i + 1] + a[i];

        minsuf[i] = min(minsuf[i + 1], suf[i]);

    }

    // 枚举子数组1的结尾位置,要给子数组2和3留至少两个位置

    int s = 0;

    for (int i = 1; i + 2 <= n; i++)

    {

        // 计算子数组1的前缀和

        s += a[i];

        if (s < 0)

            continue;

        // 如果子数组1的前缀和小于0，后面的处理就没用了

        //  3. 检查后缀 suf[i+1] 与更右侧的最小后缀 minsuf[i+2] 之间的关系：

        //     suf[i+1] = sum(arr[i+1..n])

        //     minsuf[i+2] = min_{j ≥ i+2} sum(arr[j..n])

        //

        //     若 suf[i+1] ≥ minsuf[i+2]，则存在某个 j ≥ i+2 使得

        //       suf[i+1] - suf[j] = sum(arr[i+1..j-1]) ≥ 0

        //     也就是说，紧跟在前缀后面，可以找出一个非空的“中间段” arr[i+1..j-1]，

        //     其和也是 ≥ 0。这样：

        //       sum(arr[1..i]) ≥ 0  且  sum(arr[i+1..j-1]) ≥ 0，

        //     拼起来就是一个以 1 开始、长度 ≥ 2 的子区间，和 ≥ 0。

        //     因此，满足条件，返回 true。

        if (suf[i + 1] >= minsuf[i + 2])

            return true;

    }

    return false;

}

  

void solve()

{

    int n, k;

    cin >> n >> k;

    vector<int> a(n + 10, 0);

    for (int i = 1; i <= n; i++)

    {

        int x;

        cin >> x;

        a[i] = (x <= k ? 1 : -1);

    }

    // 首先我们判断子数组1和子数组3加起来和为非负的情况（最简单）

    int q = n + 1, b = -1;

    int s = 0;

    // 从左到右，找到第一个前缀和大于等于0的位置，即第一段子数组

    for (int i = 1; i <= n; i++)

    {

        s += a[i];

        if (s >= 0)

        {

            q = i;

            break;

        }

    }

    s = 0;

    // 从右到左，找到第一个后缀和大于等于0的位置，即第三段子数组

    for (int i = n; i >= 1; i--)

    {

        s += a[i];

        if (s >= 0)

        {

            b = i;

            break;

        }

    }

    // 如果a+1<b,则说明不仅存在两个子数组加起来大于等于0，并且还有一段能拿来做子数组2

    if (q + 1 < b)

    {

        cout << "YES\n";

        return;

    }

    // 否则，我们开始判断子数组1和子数组2加起来大于等于0的情况，2和3加起来大于等于0的情况是对称的

    if (check_prefix_and_middle(a, n))

    {

        cout << "YES\n";

        return;

    }

    // 反转一下数组a，再判断一次2和3加起来大于等于0的情况

    reverse(a.begin() + 1, a.begin() + n + 1);

    if (check_prefix_and_middle(a, n))

    {

        cout << "YES\n";

        return;

    }

    cout << "NO\n";

}

  

int main()

{

    // ios::sync_with_stdio(0);

    // cin.tie(0);

    int t;

    cin >> t;

    while (t--)

    {

        solve();

    }

    return 0;

}
```

