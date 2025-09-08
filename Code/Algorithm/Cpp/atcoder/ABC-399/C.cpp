#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int pre[N], num[N];

int root(int x)
{
    if (pre[x] == x)
    {
        return x;
    }
    else
    {
        int p_root = root(pre[x]);
        pre[x] = p_root;
        return p_root;
    }
}

void merge(int x, int y)
{
    int x_root = root(x);
    int y_root = root(y);
    if (x_root == y_root)
        return;                 // 若有重边或自环，直接返回
    pre[x_root] = y_root;       // 合并
    num[y_root] += num[x_root]; // 更新根节点的连通节点数量
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = i;
        num[i] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    int ans = m;
    for (int i = 1; i <= n; i++)
    {
        if (pre[i] == i) // 找到根节点
        {
            ans = ans - (num[i] - 1);
        }
    }
    cout << ans << "\n";
    return 0;
}