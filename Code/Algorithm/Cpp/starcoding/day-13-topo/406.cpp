/*
暴力dfs时间复杂度为o(n^2)
优化使用dp
使用bitset<N>f[N]
f[j][i]代表能否从i到j
x->y即可翻译为
能到x的，都能到y
即if(f[x][i])f[y][i]=true;
再遍历for(i:range(0,n)){
    if(f[x][i])f[y][i]=true;
}
就能统计节点i能到达多少个点
我们可以发现这个符合或运算，所以我们可以简化为
f[y]|=f[x]
意思是所有能到x的节点都能到y
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e3 + 10;
vector<vector<int>> g(N, vector<int>());
ll ind[N];
int n, m;
bitset<N> f[N];

void topo()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        f[i][i] = true; // i可以自己到自己
        if (ind[i] == 0)
            q.push(i);
    }
    while (q.size())
    {
        int x = q.front();
        q.pop();
        for (auto &y : g[x])
        {
            // x->y,能到x的，都能到y
            f[y] |= f[x];
            ind[y]--;
            if (ind[y] == 0)
                q.push(y);
        }
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        ind[v]++;
        g[u].push_back(v);
    }
    topo();
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (f[j][i])
                cnt++;
        }
        cout << cnt << " ";
    }
    cout << "\n";
}

int main()
{
    int _ = 1;
    while (_--)
    {
        solve();
    }
    return 0;
}