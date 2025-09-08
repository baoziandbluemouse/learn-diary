#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
typedef long long ll;
const ll inf = 0x3f3f3f3f;
// djkstra算法 处理单源最短路 时间复杂度O(nlogn)
struct node
{
    ll x, w; // x表示出点，w表示权值
    bool operator<(const node &v) const
    {
        return w == v.w ? (x < v.x) : (w > v.w); // 重载<运算符，(优先比较权值）w从小到大排序,若权值相等，则按x排序
        // 注意优先队列的比较器是相反的，要小根堆，就得是w>v.w,和sort函数之类的比较器写法相反
    }
};
vector<vector<node>> g(N, vector<node>());
ll d[N], n, m;

void dijkstra(int st)
{
    memset(d, 0x3f, sizeof(ll) * (n + 1));
    d[st] = 0;
    bitset<N> vis;           // 记录已经被拓展过的
    priority_queue<node> pq; // 进入队列的点，按权值从小到大排序
    pq.push({st, d[st]});    // 将源点加入优先队列
    while (pq.size())
    {
        int u = pq.top().x;
        pq.pop();
        if (vis[u]) // 跳过冗余点
            continue;
        vis[u] = true; // 标记u已得到最短距离，不再更新
        for (const auto &edge : g[u])
        {
            int v = edge.x;
            int w = edge.w;
            if (!vis[v] && d[v] > d[u] + w) // 如果vis[v]为true，则该点已得到最短路径，无需更新
            {
                d[v] = d[u] + w;
                pq.push({v, d[v]});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (u != v) // 避免自环
        {
            g[u].push_back({v, w});
        }
    }

    dijkstra(1);

    cout << (d[n] >= inf ? -1 : d[n]) << "\n"; // 输出d[n]，若d[n]未被更新，则输出-1(即d[n]>=0x3f3f3f3f)

    return 0;
}