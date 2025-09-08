#include <bits/stdc++.h>
using namespace std;
const int N = 30;
char g[N][N];
bool st[N][N];                                  // 存储每个格子是否走过
int n, m;                                       // n行m列
int cnt = 0;                                    // 记录走过的格子数
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1}; // 向量数组，表示上右下左四个方向
void dfs(int x, int y);                         // 从x行y列开始走
int main(void)
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", g[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == '@')
            {
                st[i][j] = true;
                dfs(i, j);
            }
        }
    }
    cnt++;

    cout << cnt << "\n";
    return 0;
}

void dfs(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= n || b < 0 || b >= m)
            continue;
        if (g[a][b] != '.')
            continue;
        if (st[a][b]) // 走过了就不再走了，因为一个格子开始走，按照递归的逻辑绝对会把四周全部遍历完，所以不需要回头路
            continue;
        // 走到（a，b）这个格子
        cnt++;
        st[a][b] = true;
        dfs(a, b);
    }
}