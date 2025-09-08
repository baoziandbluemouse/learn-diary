#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int a[N][N], c[N];
int n, m, ans = 1e9;
void dfs(int x, int y, int cnt)
{
    // 按照递增顺序连边，防止重复搜索
    // 搜索注意度数的更新与回溯，当所有点都考虑完后，检查是否满足每个点的度数都为2，然后更新答案。
    // x：起点   y：下一个点的范围是[y,n]  cnt:操作次数
    if (x == n + 1)
    {
        // 所有点考虑完了
        //  遍历是否为2
        for (int i = 1; i <= n; i++)
        {
            if (c[i] != 2)
            {
                return;
            }
        }
        ans = min(ans, cnt);
        return;
    }
    if (y >= n + 1)
    {
        // 如果y已经超出n，那就说明x这个起点已经把所有点连过一遍
        // 接下来要从x+1作为起点
        dfs(x + 1, x + 2, cnt);
        return;
    }
    // 第一种操作 把x和y连接
    c[x]++;
    c[y]++;
    if (c[x] <= 2 && c[y] <= 2)
    {
        dfs(x, y + 1, cnt + (a[x][y] == 0));
        // 判断是否是新增边
    }
    // 回溯
    c[x]--;
    c[y]--;
    // 第二种操作，删边
    //  x连下一个点，即不和y连了，下一个点是y+1
    //  注意如果x-y原本有边，需要操作一次把边删了
    dfs(x, y + 1, cnt + a[x][y]);
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u][v] = a[v][u] = 1;
    }
    dfs(1, 2, 0);
    cout << ans;
    return 0;
}