#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> c(n + 1, 0); // 桶数组计算下数字个数
    for (int x : a)
    {
        c[x]++;
    }
    vector<int> pc(n + 1, -1); // 上一次mex变化的c数组
    vector<int> nc(n + 1, 0);  // 下一次mex变化的c数组
    while (k)
    {
        k--;
        int w = 0;
        while (c[w])
            w++;             // 计算出当前c数组中的mex为什么
        nc.assign(n + 1, 0); // 把nc清空并重置为全零数组
        for (int i = 0; i <= n; i++)
        {
            if (i < w && c[i] == 1)
            {
                nc[i] += c[i]; // 如果数字小于mex，并且又只有一个，那么肯定是不会变的
            }
            else
            {
                nc[w] += c[i];
            }
        }
        // 经过草稿计算可以发现，我们只需进行有限次暴力运算，就能达到答案
        // 实际时间复杂度不会很高
        if (pc == nc) // 当上一次和下一次的都相等，那就说明进入循环了，直接退出去，根据k的值来判断
            break;
        pc = c;
        c = nc;
    }
    auto res = c;
    if (k % 2 == 0)
    {
        res = nc;
    }
    else
    {
        res = c;
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans += (ll)i * res[i];
    }
    cout << ans << "\n";
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