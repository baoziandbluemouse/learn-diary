#include <bits/stdc++.h>
using namespace std;
const int N = 15;
char g[N][N];
bool st[N];  // 记录已经选过的列
int n, m;    // n为几阶方阵，m为棋数目
int res = 0; // 记录方案数

void dfs(int x, int cnt); // x代表第几行，从第一行开始，每个位置有n种选择，并且是排列枚举，
// 根据st数组来判断这一列（即选择）是否s已经被选过,cnt代表已经选了几个棋子

int main(void)
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        if (n == -1 && m == -1)
        {
            break;
        }
        cin.ignore();
        for (int i = 0; i < n; i++)
        {
            scanf("%s", g[i]);
        }
        res = 0;
        dfs(0, 0);
        cout << res << "\n";
    }
    return 0;
}

void dfs(int x, int cnt)
{
    if (cnt == m)
    {
        res++;
        return;
    }
    if (x > n - 1)
    {
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!st[i] && g[x][i] == '#')
        {
            st[i] = true;
            dfs(x + 1, cnt + 1);
            st[i] = false;
        }
    }
    dfs(x + 1, cnt); // 表示这行我们不放棋子，直接进入下一行
}