#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5005;
//  prime
//  struct node
//  {
//      int u, w;
//      bool operator<(const node &v) const
//      {
//          return (w == v.w) ? (u < v.u) : (w > v.w);
//      }
//  };
//  vector<vector<node>> g(N, vector<node>());
//  bitset<N> intree;
//  int dis[N];
//  int main()
//  {
//      ios::sync_with_stdio(0);
//      cin.tie(0);
//      cout.tie(0);
//      int n, m;
//      cin >> n >> m;
//      for (int i = 1; i <= m; i++)
//      {
//          int u, v, w;
//          cin >> u >> v >> w;
//          g[u].push_back({v, w});
//          g[v].push_back({u, w});
//      }
//      memset(dis, 0x3f, sizeof(dis));
//      priority_queue<node> q;
//      // 开始
//      dis[1] = 0;
//      q.push({1, 0});
//      ll ans = 0;
//      while (q.size())
//      {
//          int u = q.top().u;
//          q.pop();
//          if (intree[u])
//              continue;
//          intree[u] = true;
//          ans += dis[u];
//          dis[u] = 0;
//          // 更新
//          for (auto &v : g[u])
//          {
//              int w = v.w;
//              int u = v.u;
//              if (!intree[u] && dis[u] > w)
//              {
//                  dis[u] = w;
//                  q.push({u, w});
//              }
//          }
//      }
//      for (int i = 1; i <= n; i++)
//      {
//          if (!intree[i])
//          {
//              cout << "orz\n";
//              return 0;
//          }
//      }
//      cout << ans << "\n";
//      return 0;
//  }

// kruskal
int pre[N];
struct edge
{
    int u, v, w;

    bool operator<(const edge &b) const
    {
        if (w != b.w)
        {
            return w < b.w;
        }
        else if (u != b.u)
        {
            return u < b.u;
        }
        return v < b.v;
    }
};

int root(int x)
{
    if (pre[x] == x)
    {
        return x;
    }
    else
    {
        int root_x = root(pre[x]);
        pre[x] = root_x;
        return root_x;
    }
}

void merge(int x, int y)
{
    pre[root(x)] = root(y);
}

bool isCon(int x, int y)
{
    return root(x) == root(y);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = i; // 初始化并查集
    }
    vector<edge> e;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e.push_back({u, v, w});
    }
    sort(e.begin(), e.end());
    ll ans = 0;
    for (auto &i : e)
    {
        int u = i.u;
        int v = i.v;
        int w = i.w;
        if (isCon(u, v))
        {
            continue;
        }
        merge(u, v);
        ans += w;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!isCon(i, 1))
        {
            cout << "orz\n";
            return 0;
        }
    }
    cout << ans << "\n";
    return 0;
}