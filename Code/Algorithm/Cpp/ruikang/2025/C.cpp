#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5+10;
struct node{
	int stx;
	int sty;
	int edx;
	int edy;
};
map<node,int>mp;
int vis[N];
int con[N];
int n,m,s;
int cnt_0,cnt_1;

bool checkxy(int a,int b)
{
	if(a <1 || a>n || b<1 || b>m)
	{
		return true;
	}
	return false;
}

bool checkcon()
{
	for(auto &e:mp)
	{
		node t = e.first;
		if(mp.count({t.stx,t.sty,t.stx-1,t.sty}) && mp.count({t.stx,t.sty,t.stx,t.sty-1}))
		{
			if(mp.count({t.stx-1,t.sty,t.stx-1,t.sty-1}) && mp.count({}))
		}
	}
}

void solve()
{
	memset(vis,-1,sizeof(vis));
	cin>>n>>m>>s;
	for(int i=1;i<=s;i++)
	{
		int p,stx,sty,edx,edy;
		cin>>p>>stx>>sty>>edx>>edy;
		if(i == 1 && p == 1)
		{
			vis[i]=2;
			continue;
		}
		if(checkxy(stx,sty) || checkxy(edx,edy))
		{
			vis[i]=2;
			continue;
		}
		if(abs(stx-edx) == 1 && abs(stx-edx) == abs(sty-edy))
		{
			vis[i]=2;
			continue;
		}
		if(stx == edx && sty == edy)
		{
			vis[i]=2;
			continue;
		}
		if(i!=1)
		{
			for(int j=i;j>=1;j--)
			{
				if(vis[j] == 2)
				{
					continue;
				}
				if(con[j-1] != 1)
				{
					if(p == vis[j-1])
					{
						vis[j]=2;
						continue;
					}
				}
				else
				{
					if(p != vis[j-1])
					{
						vis[j] =2;
						continue;
					}
				}
			}
		}
		vis[i] = p;
		mp[{stx,sty,edx,edy}]=1;
		mp[{edx,edy,stx,sty}]=1;
		if(checkcon())
		{
			con[i]=1;
		}
	}
	for(int i=1;i<=s;i++)
	{
		if(vis[i] == 2)
		{
			cout<<i<<" ";
		}
	}
	cout<<"\n";
	if(cnt_0 > cnt_1)
	{
		cout<<0<<" "<<cnt_0<<"\n";
	}
	else
	{
		cout<<1<<" "<<cnt_1<<"\n";
	}
}




int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int _ = 1;
	//cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}
