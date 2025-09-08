#include<bits/stdc++.h>
using namespace std;
using ll = long long;


void solve()
{
	int n,s;
	cin>>n>>s;
	int cnt = 0;
	int sum = 0;
	for(int i=1;i<=n;i++)
	{
		int w,v;
		cin>>w>>v;
		if(w == 1)
		{
			cnt++;
		}
		sum+=v;
	}
	if(cnt >= ((n+1)/2))
	{
		cout<<1<<" ";
	}
	else
	{
		cout<<0<<" ";
	}
	if(sum-50>=s)
	{
		cout<<1<<"\n";
	}
	else
	{
		cout<<0<<"\n";
	}
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
