#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
using ll = long long;
const int N = 5010;
int n;
//const int N = 1e6+10;
int a[N];
bitset<N>vis;
vector<vector<int>>g(N,vector<int>());

int dfs(int u,int cnt)
{
	int res = 0;
	if(u > n || u == 0){
		return 0;
	}
	for(auto &i:g[u])
	{
		if(vis[i])
		{
			continue;
		}
		vis[i]=1;
		if(a[i] == 1)
		{
			dfs(i,cnt+1);
		}
		else
		{
			dfs(i,cnt);
		}
		vis[i]=0;
	}
	res = max(res,cnt);
	return res;
}


int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		int res = 0;
		if(a[i] == 1)
		{
			vis[i]=1;
			res = dfs(i,1);
		}
		else
		{
			vis[i]=1;
			res = dfs(i,0);
		}
		ans = max(res,ans);
		vis.reset();
	}
	cout<<ans<<"\n";
	return 0;
}
