---
date: 2025-04-28
---

# [C-小苯的逆序对和_牛客周赛 Round 91](https://ac.nowcoder.com/acm/contest/108038/C)


前缀最大值没有想到，令人感叹



```cpp
#include <iostream>

#include <vector>

using namespace std;

using ll = long long;

  

void solve()

{

    int n;

    cin >> n;

    vector<int> a(n + 1, 0);

    for (int i = 1; i <= n; i++)

    {

        cin >> a[i];

    }

    vector<int> premax(n + 1, 0);

    for (int i = 1; i <= n; i++)

    {

        premax[i] = max(premax[i - 1], a[i]);

    }

    int sum = 0;

    for (int j = n; j >= 1; j--)

    {

        if (premax[j - 1] > a[j])

        {

            sum = max(sum, premax[j - 1] + a[j]);

        }

    }

    cout << sum << "\n";

}

  

int main()

{

    int t;

    cin >> t;

    while (t--)

    {

        solve();

    }

    return 0;

}
```













# [D-数组4.0_牛客周赛 Round 91](https://ac.nowcoder.com/acm/contest/108038/D)




```cpp
#include <bits/stdc++.h>

using namespace std;

  

void solve()

{

    map<int, int> cnt;

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)

    {

        int x;

        cin >> x;

        cnt[x]++;

    }

    int ans = 0;

    for (auto &t : cnt)

    {

        // 假设我们有一个连着的段，他的起点是t.first,那既然起点是t.first，就说明前面断开来了

        // 根据题目的条件，断开来就说明t.first-1是不存在的，所以我们可以用这个来判断有几个段数

        // 最后答案就是段数-1

        if (!cnt.count(t.first - 1))

        {

            ans++;

        }

        // 并且还有一个特殊情况，就是这个段他只有一个数孤立组成，那我们要连的时候就要把则会个数字的个数加上

        if (!cnt.count(t.first + 1) && !cnt.count(t.first - 1))

            ans += t.second - 1;

    }

    cout << ans - 1 << "\n";

}

  

int main()

{

    int t;

    cin >> t;

    while (t--)

    {

        solve();

    }

    return 0;

}
```