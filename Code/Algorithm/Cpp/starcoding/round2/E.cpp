#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll a[N];
vector<vector<int>> g(N, vector<int>());
ll ind[N];
int n;

void topo()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (ind[i] == 1)
            q.push(i);
    }
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto &v : g[u])
        {
            ind[v]--;
            if (ind[v] == 1)
                q.push(v);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        // 自环的情况，由于基环树只有一个环，所以a[u]就是答案了
        if (u == v)
        {
            cout << a[u] << "\n";
            return 0;
        }
        g[u].push_back(v);
        ind[v]++;
        g[v].push_back(u);
        ind[u]++;
    }
    ll ans = 0;
    // 只有1或2个节点的情况，不难看出把a[i]加完后就是答案了
    if (n <= 2)
    {
        for (int i = 1; i <= n; i++)
        {
            ans += a[i];
        }
        cout << ans << "\n";
    }
    else
    {
        topo();
        // 进行一次拓扑排序，只剩下了环存在，环上的节点他们的入度都是2
        for (int i = 1; i <= n; i++)
        {
            if (ind[i] == 2)
            {
                ans += a[i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}