#include <bits/stdc++.h>
using namespace std; // 洪水模型
const int N = 110;
char g[N][N];
bool st[N][N]; // 记录有没有被水慢过
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1}; // 八个方向 上 右上 右 右下 下 左下 左 左上
int n, m;
int cnt = 0;
void dfs(int x, int y);
int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", g[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == 'W' && !st[i][j])
            {
                st[i][j] = true;
                dfs(i, j);
                cnt++; // 已经判断出一个联通块了，所以+1,若cnt在dfs中，则增加的是一个联通块中的格子数
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}

void dfs(int x, int y)
{
    for (int i = 0; i < 8; i++)
    {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= n || b < 0 || b >= m)
            continue;
        if (g[a][b] == '.')
            continue;
        if (st[a][b])
            continue;
        st[a][b] = true;
        dfs(a, b);
    }
}