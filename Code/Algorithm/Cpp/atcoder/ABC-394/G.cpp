#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int M = 1e6 + 5;
int f[505][505];
int a[N], b[N], y[N], c[N], d[N], z[N], l[N], r[N], ans[N];

vector<pair<int, int>> g[M]; // g[i] -> 楼高为i的相邻楼方案
vector<int> check[M];        // check[i] -> 高度为i时需要check的询问编号

int fa[505 * 505];

int find(int x) // 并查集找根
{
    if (fa[x] == x)
    {
        return x;
    }
    else
    {
        int root_x = find(fa[x]);
        fa[x] = root_x;
        return root_x;
    }
}
void merge(int x, int y) // 并查集合并
{
    int fx = find(x), fy = find(y);
    if (fx == fy)
        return;
    fa[fx] = fy;
}
void init() // 初始化并查集
{
    for (int i = 0; i < 505 * 505; i++)
        fa[i] = i;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> f[i][j];
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> a[i] >> b[i] >> y[i] >> c[i] >> d[i] >> z[i];
    }
    // 下面以水平和垂直方向分别处理网格结构中相邻单元格之间的连通性关系
    // 垂直方向
    // 遍历每一行，最后一行除外
    for (int i = 1; i < n; i++)
        for (int j = 1; j <= m; j++)
            // 将当前单元格(i,j)和下方单元格(i+1,j)之间的最小高度值作为键，取最小高度才能让他们在当前高度连通
            g[min(f[i][j], f[i + 1][j])].push_back({(i - 1) * m + (j - 1), i * m + (j - 1)});
    // 存储的第一个是当前单元格的线性索引，第二个是下方单元格的线性索引
    // 即把二维的下标压缩成一维的

    // 水平方向
    // 遍历每一列，最后一列除外
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < m; j++)
            g[min(f[i][j], f[i][j + 1])].push_back({(i - 1) * m + (j - 1), (i - 1) * m + j});

    // 设定二分范围上限
    const int lim = 1e6;

    // 初始化所有查询的二分区间
    for (int i = 1; i <= q; i++)
        l[i] = 1, r[i] = lim;

    // 整体二分
    while (1)
    {

        int ok = 1;
        // 清空check数组
        for (int i = 0; i <= lim; i++)
            check[i].clear();
        for (int i = 1; i <= q; i++) // 每个询问
        {
            if (l[i] > r[i])
                continue;
            int mid = (l[i] + r[i]) >> 1; // 取中间高度
            check[mid].push_back(i);      // 记录需要在该高度检查的询问
            ok = 0;                       // 标记有未处理的询问
        }
        if (ok) // 如果所有询问都处理完了，退出循环
            break;
        // 初始化并查集
        init();
        // 从高到低处理所有高度
        for (int i = lim; i >= 0; i--)
        {
            // 合并所有相邻格子
            for (auto [u, v] : g[i])
                merge(u, v);
            for (auto id : check[i])
            { // 判断能否从给定的(a,b)到达(c,d)
                int u = (a[id] - 1) * m + (b[id] - 1);
                int v = (c[id] - 1) * m + (d[id] - 1);
                if (find(u) == find(v))
                {
                    ans[id] = i;   // 记录当前高度可行
                    l[id] = i + 1; // 缩小二分区间，尝试寻找更高的可行解
                }
                else
                {
                    r[id] = i - 1;
                }
            }
        }
    }
    for (int i = 1; i <= q; i++)
        cout << y[i] + z[i] - 2 * min({ans[i], y[i], z[i]}) << endl;

    return 0;
}