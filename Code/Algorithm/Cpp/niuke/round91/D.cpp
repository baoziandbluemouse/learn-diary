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