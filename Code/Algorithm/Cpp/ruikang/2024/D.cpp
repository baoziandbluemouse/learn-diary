#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> bfs(vector<vector<int>> &g, int st, vector<int> &vis)
{
	queue<int> q;
	vector<int> components;
	q.push(st);
	components.push_back(st);
	while (q.size())
	{
		auto t = q.front();
		q.pop();
		for (auto &x : g[t])
		{
			if (!vis[x])
			{
				vis[x] = 1;
				q.push(x);
				components.push_back(x);
			}
		}
	}
	return components;
}

int topo(vector<int> &componets, vector<vector<int>> &g)
{
	// 为当前连通分量创建度数数组
	vector<int> deg(g.size(), 0);
	for (auto &x : componets)
	{
		deg[x] = g[x].size();
	}
	queue<int> q;
	// 将所有度数为1的点加入
	for (auto &x : componets)
	{
		if (deg[x] == 1)
		{
			q.push(x);
		}
	}
	while (q.size())
	{
		auto t = q.front();
		q.pop();
		for (auto &x : g[t])
		{
			deg[x]--;
			if (deg[x] == 1)
			{
				q.push(x);
			}
		}
	}
	int cnt = 0;
	for (auto &x : componets)
	{
		if (deg[x] > 2)
		{
			return -1; // 不是简单环
		}
		if (deg[x] == 2)
		{
			cnt++;
		}
	}
	return cnt;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n + 1, vector<int>());
	vector<int> vis(n + 1, 0);
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	// 进行bfs找出连通分量，对连通分量进行拓扑排序找到是否有环
	// 最终统计环的个数是否是1个，如果是一个，就给出顶点个数，如果不是，就给出环个数
	int maxx = -1;	  // 统计顶点个数
	int cyclecnt = 0; // 统计环个数
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			auto components = bfs(g, i, vis);
			int t = topo(components, g);
			if (t > 0)
			{
				maxx = t;
				cyclecnt++;
			}
		}
	}
	if (cyclecnt == 1)
	{
		cout << "Yes " << maxx << "\n";
	}
	else
	{
		cout << "No " << cyclecnt << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int _;
	cin >> _;
	while (_--)
	{
		solve();
	}
	return 0;
}
