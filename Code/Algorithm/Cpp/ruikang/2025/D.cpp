#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 15;
int n,m;

vector<int> bfs(int st,vector<int>&vis,vector<vector<int>>&g)
{
	vector<int>temp;
	queue<int>q;
	q.push(st);
	temp.push_back(st);
	vis[st]=1;
	while(q.size())
	{
		int t = q.front();
		q.pop();
		for(auto &x:g[t])
		{
			if(vis[x])
			{
				continue;
			}
			vis[x]=1;
			q.push(x);
			temp.push_back(x);
		}
	}
	return temp;
}

int topo(vector<int> &component,vector<vector<int>> &g)
{
	int indeg[15]={0};
	for(auto &x:component)
	{
		for(auto &i:g[x])
		{
			indeg[i]++;
		}
	}
	queue<int>q;
	for(auto &x:component)
	{
		if(indeg[x] == 1)
		{
			q.push(x);
		} 
	}
	while(q.size())
	{
		auto t = q.front();
		q.pop();
		for(auto &x:g[t])
		{
			indeg[x]--;
			if(indeg[x] == 1)
			{
				q.push(x);
			}
		}
	}
	int cnt = 0;
	for(auto &x:component)
	{
		if(indeg[x] == 2)
		{
			cnt++;
		}
	}
	return cnt;
}

void solve()
{
	cin>>n>>m;
	if(m == 0 || n == 1)
	{
		cout<<0<<" "<<0<<"\n";
		return;
	}
	else if(n>=2 && m == 1)
	{
		cout<<2<<" "<<2<<"\n";
		return;
	}
	vector<vector<int>>g(n+1,vector<int>());
	vector<int>vis(n+1,0);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		if(u == v)
		{
			continue;
		}
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int max_cnt = 2;
	int second_cnt = 2;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vector<int>component;
			component = bfs(i,vis,g);
			int t = topo(component,g);
			if(t>max_cnt)
			{
				second_cnt = max_cnt;
				max_cnt = t;
			}
		}
	}
	cout<<max_cnt<<" "<<second_cnt<<"\n";
}




int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int _;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}
