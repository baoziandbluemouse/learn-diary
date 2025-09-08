#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], b[N], ans;
vector<vector<int>> t1(N, vector<int>());
vector<vector<int>> t2(N, vector<int>());
void dfs(int pn, int fan, int pm, int fam, int dep)
{
    // 两棵树同时遍历
    // fan,fam代表两棵树的父节点（即上一个访问的节点）
    // pn,pm代表两棵树的当前节点
    ans = max(ans, dep);
    map<int, int> mp;
    for (auto i : t1[pn]) // 遍历当前节点的所有后继节点
    {
        if (i != fan)
        {
            mp[a[i]] = i; // 进行记录
        }
    }
    for (auto i : t2[pm]) // 遍历第二颗树的当前节点的所有后继节点
    {
        if (i != fam)
        {
            if (mp.count(b[i])) // 如果有值相同的节点
            {
                dfs(mp[b[i]], pn, i, pm, dep + 1); // 就满足条件，继续往下搜
            }
        }
    }
}
int main()
{
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> b[i];
    }
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        t1[u].push_back(v);
        t1[v].push_back(u);
    }
    for (int i = 1; i < m; i++)
    {
        cin >> u >> v;
        t2[u].push_back(v);
        t2[v].push_back(u);
    }
    if (a[1] != b[1])
    {
        cout << 0;
        return 0;
    }
    dfs(1, 0, 1, 0, 1);
    cout << ans << '\n';
    return 0;
}