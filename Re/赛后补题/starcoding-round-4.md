---
date: 2025-06-03
---
# [区间开根号【入门教育赛】 | 星码StarryCoding 算法竞赛新手村](https://www.starrycoding.com/contest/18/D)

**并查集妙用**，挺好的题


```cpp
// #include <bits/stdc++.h>

// using namespace std;

// const int N = 1e5 + 5;

// using ll = long long;

  

// ll a[N], pre[N];

// // find(i)指向i右侧最近的非1位置

// // 考虑如何将已经变为1的元素快速跳过，我们可以使用并查集

// int find(int x)

// {

//     if (pre[x] == x)

//     {

//         return x;

//     }

//     else

//     {

//         int find_x = find(pre[x]);

//         pre[x] = find_x;

//         return find_x;

//     }

// }

  

// int main()

// {

//     int n;

//     cin >> n;

//     for (int i = 1; i <= n; i++)

//     {

//         cin >> a[i];

//     }

//     ll ans = 0;

//     for (int i = 1; i <= n; i++)

//     {

//         pre[i] = i;

//     }

//     for (int i = 1; i <= n; i++)

//     {

//         if (a[i] == 1)

//         {

//             ans++;

//             pre[find(i)] = find(i + 1);

//         }

//     }

//     ll q;

//     cin >> q;

//     while (q--)

//     {

//         int l, r;

//         cin >> l >> r;

//         for (int i = find(l); i <= r; i++)

//         {

//             if (a[i] == 1)

//             {

//                 // 跳过已经为1的

//                 i = find(i) - 1; // 要-1是因为会for循环+1

//                 continue;

//             }

  

//             a[i] = sqrt(a[i]);

//             if (a[i] == 1)

//             {

//                 // 所有边从左往右

//                 ans++;

//                 pre[find(i)] = find(i + 1);

//             }

//         }

//         cout << ans << "\n";

//     }

//     return 0;

// }

  

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 1e5 + 5;

const ll inf = 2e18;

ll a[N], pre[N];

// find(i)指向i右侧最近的非1位置

int find(int x) { return pre[x] = (pre[x] == x ? x : find(pre[x])); }

  

int main()

{

    ll n;

    cin >> n;

    for (int i = 1; i <= n; ++i)

        cin >> a[i];

    int ans = 0;

    for (int i = 1; i <= n + 1; ++i)

        pre[i] = i;

    for (int i = 1; i <= n; ++i)

        if (a[i] == 1)

            ans++, pre[find(i)] = find(i + 1);

    ll q;

    cin >> q;

    while (q--)

    {

        int l, r;

        cin >> l >> r;

        for (int i = find(l); i <= r; ++i)

        {

            if (a[i] == 1)

            {

                // 跳过已经处理过的

                i = find(i) - 1;

                continue;

            }

  

            a[i] = sqrt(a[i]);

            if (a[i] == 1)

            {

                // 所有边都是从左往右的

                ans++;

                pre[find(i)] = find(i + 1);

            }

        }

        cout << ans << '\n';

    }

    return 0;

}
```


