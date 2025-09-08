#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int g[1005][4];
void solve()
{
	int n,m;
	int a1,a2,b1,b2,b3;
	cin>>n>>m;
	cin>>a1>>a2>>b1>>b2>>b3;
	int ans1 = 0;
	for(int i=1;i<=n;i++)
	{
		int u,op;
		cin>>u>>op;
		if(op == 1)
		{
			g[u][1]-=b1;
			ans1+=a1;
		}
		else if(op == 2)
		{
			g[u][2]-=b2;
		}
		else if(op == 3)
		{
			g[u][3]-=b3;
			ans1-=a2;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int u,op;
		cin>>u>>op;
		g[u][op]=g[u][op]/2;
	}
	int ans2 = 0;
	for(int i=1;i<=1000;i++)
	{
		int sum = g[i][1]+g[i][2]+g[i][3];
		ans2+=sum;
	}
	cout<<ans1<<" "<<ans2<<"\n";
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
