#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 25
int cnt = 0, n, r, t;
void dfs(int x, int start, int sum);

int main(void)
{
    cin >> t;
    while (t--)
    {
        cin >> n >> r;
        dfs(1, 1, 0);
        cout << cnt << "\n";
        cnt = 0;
    }
    return 0;
}

void dfs(int x, int start, int sum) // x记录枚举到哪个位置，start记录当前位置从几开始枚举
{
    if (sum == n)
    {
        cnt++;
        return;
    }
    else if (sum > n)
    {
        return;
    }
    if (x > r)
    {
        return;
    }
    for (int i = start; i <= n; i++)
    {
        dfs(x + 1, i, sum + i);
    }
}