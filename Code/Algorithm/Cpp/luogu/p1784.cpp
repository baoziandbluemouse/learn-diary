#include <bits/stdc++.h>
using namespace std;
const int N = 11;
bool row[N][N], col[N][N], fz[N][N]; // 行，列，方阵 这里第二维记录的是数字具体为几
int g[N][N];                         // 记录输入的数

void solve()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }
    exit(0); // 直接退出
}

void dfs(int x, int y)
{
    if (g[x][y]) // 如果这个地方有数字，则跳过
    {
        if (x == 9 && y == 9) // 如果到了最后一个点
        {
            solve();
        }
        else if (y == 9)
        {
            dfs(x + 1, 1); // 列数满了，跳转到下一行,继续从1开始
        }
        else
        {
            dfs(x, y + 1); // 当前行的列没遍历完，继续遍历下一列
        }
    }
    else // 没数字，可以填充
    {
        for (int i = 1; i <= 9; i++)
        {
            if (!row[x][i] && !col[y][i] && !fz[(x - 1) / 3 * 3 + (y - 1) / 3 + 1][i]) // 没有重复
            {
                row[x][i] = col[y][i] = fz[(x - 1) / 3 * 3 + (y - 1) / 3 + 1][i] = true; // 标记
                g[x][y] = i;                                                             // 填充
                if (x == 9 && y == 9)                                                    // 如果到了最后一个点
                {
                    solve();
                }
                else if (y == 9)
                {
                    dfs(x + 1, 1); // 列数满了，跳转到下一行,继续从1开始
                }
                else
                {
                    dfs(x, y + 1); // 当前行的列没遍历完，继续遍历下一列
                }
                row[x][i] = col[y][i] = fz[(x - 1) / 3 * 3 + (y - 1) / 3 + 1][i] = false; // 回溯
                g[x][y] = 0;                                                              // 回溯
            }
        }
    }
}

int main()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            int x;
            cin >> x;
            if (x != 0)
            {
                row[i][x] = true;
                col[j][x] = true;
                fz[(i - 1) / 3 * 3 + (j - 1) / 3 + 1][x] = true;
                // 计算方阵几的公式
                // 这里的i-1和j-1是为了在刚到3的倍数时，能保证不超出所在方阵的范围
            }
            g[i][j] = x;
        }
    }
    dfs(1, 1);
    return 0;
}