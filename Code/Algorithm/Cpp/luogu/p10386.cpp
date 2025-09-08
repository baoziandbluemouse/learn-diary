#include <bits/stdc++.h>
using namespace std;
const int N = 5;
int ans = 0;
int a[10][10]; // 记录棋盘,1代表小蓝，2代表小桥

bool check()
{
    // 小蓝先下子，总共13枚，小桥后下子
    // 下子检查
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (a[i][j] == 1)
                cnt1++;
            else if (a[i][j] == 2)
                cnt2++;
        }
    }
    if (cnt1 - cnt2 != 1)
        return true;
    // 检查行是否胜利
    for (int i = 1; i <= N; i++)
    {
        bool flag = true;
        for (int j = 1; j <= N; j++)
        {
            if (a[i][j] != a[i][1]) // 有一个不同就断掉了
            {
                flag = false;
                break;
            }
        }
        if (flag) // 有一行全相同
        {
            return true;
        }
    }
    // 检查列是否胜利
    for (int i = 1; i <= N; i++)
    {
        bool flag = true;
        for (int j = 1; j <= N; j++)
        {
            if (a[j][i] != a[1][i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            return true;
        }
    }
    // 检查左对角线是否胜利
    bool flag = true;
    for (int i = 1; i <= N; i++)
    {
        if (a[i][i] != a[1][1])
        {
            flag = false;
            break;
        }
    }
    if (flag)
        return true;
    // 检查右对角线是否胜利
    flag = true;
    for (int i = 1; i <= N; i++)
    {
        if (a[i][N - i + 1] != a[1][N])
        {
            flag = false;
            break;
        }
    }
    if (flag)
        return true;
    return false;
}

void dfs(int x, int y)
{
    if (y == N + 1) // 列数满了，跳转到下一行,继续从1开始
    {
        dfs(x + 1, 1);
        return; // 这里一定要return，否则会继续往下执行
    }
    if (x == N + 1)
    {
        if (!check())
            ans++;
        return;
    }
    // 小蓝填
    a[x][y] = 1;
    dfs(x, y + 1);
    a[x][y] = 0;
    // 小桥填
    a[x][y] = 2;
    dfs(x, y + 1);
    a[x][y] = 0;
}

int main()
{
    dfs(1, 1);
    cout << ans << "\n";
    return 0;
}