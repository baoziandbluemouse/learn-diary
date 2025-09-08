#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
struct node
{
    int id, w;
};
vector<node> g[N];
bool vis[N];

bool check(int x)
{
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while (q.size())
    {
        int t = q.front();
        q.pop();
        for (auto &i : g[t])
        {
            if (vis[i.id])
            {
                continue;
            }
            if ((i.w & x) == i.w)
            {
                // 如果i.w是x的子集，那么就说明最后到达N点时，答案是x,这个结点不会改变答案
                q.push(i.id);
                vis[i.id] = 1;
            }
        }
    }
    return vis[n];
}
int main()
{
    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    int ans = (1 << 30) - 1;
    // 从高位开始逐个位进行判断
    for (int i = 29; i >= 0; i--)
    {
        int x = ans - (1 << i);
        // 看看这个位取零，能不能走到N结点
        if (check(x))
        {
            ans = x;
        }
    }
    cout << ans << "\n";
    return 0;
}