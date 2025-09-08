#include <bits/stdc++.h>
using namespace std;
// 组合枚举
void dfs(int x, int start, int sum); // x代表从位置几开始枚举，start代表枚举数字的起点
int n, k;
int res = 0;
int main(void)
{
    cin >> n >> k;
    dfs(1, 1, 0);
    cout << res << "\n";
    return 0;
}
void dfs(int x, int start, int sum)
{
    if (x > k)
    {
        if (sum == n)
        {
            res++;
        }
        return;
    }
    for (int i = start; sum + (k - x + 1) * i <= n; i++)
    {
        dfs(x + 1, i, sum + i);
    }
}