#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1005;

struct node{
	int v,val,tim;
	bool operator< (const node& b)const
	{
		if(val != b.val)
		{
			return val>b.val;
		}
		else if(tim != b.tim)
		{
			return tim>b.tim;
		}
		else
		{
			return v>b.v;
		}
	}
};

vector<node>g[N];
int cost[N];
int n,m,st,ed;
bitset<N>vis;
vector<ll>dis_tim(N,0x3f3f3f3f);
vector<ll>dis_val(N,0x3f3f3f3f);
int maxx;
int last[N];

void dijkstra()
{
	priority_queue<node>pq;
	
	dis_tim[st]=0;
	dis_val[st]=0;
	pq.push({st,dis_val[st],dis_tim[st]});
	while(pq.size())
	{
		auto u = pq.top().v;
		pq.pop();
		if(vis[u])
		{
			continue;
		}
		vis[u] = 1;
		for(auto &edge:g[u])
		{
			int v = edge.v;
			ll val = edge.val;
			ll tim = edge.tim;
			if(vis[v])
			{
				continue;
			}
			if(dis_val[v] >= dis_val[u] + val)
			{
				if(dis_val[v] > dis_val[u] + val)
				{
					dis_val[v]=dis_val[u]+val;
					dis_tim[v]=dis_tim[u]+tim;
					pq.push({v,dis_val[v],dis_tim[v]});
					last[v]=u;
				}
				if(dis_tim[v] > dis_tim[u] + tim)
				{
					dis_val[v]=dis_val[u]+val;
					dis_tim[v]=dis_tim[u]+tim;
					pq.push({v,dis_val[v],dis_tim[v]});
					last[v]=u;
				}
			}
		}
	}
}




void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>cost[i];
	}
	for(int i=1;i<=m;i++)
	{
		int a,b,w;
		cin>>a>>b>>w;
		g[a].push_back({b,cost[b],w});
		g[b].push_back({a,cost[a],w});
	}
	cin>>st>>ed;
	last[st]=0;
	dijkstra();
	int t = ed;
	while(t!=0)
	{
		maxx = max(maxx,cost[t]);
		//cout<<t<<" ";
		t = last[t];
	}
	cout<<maxx<<" "<<dis_tim[ed]<<"\n";
}


int main()
{
	int _ = 1;
	//cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}
