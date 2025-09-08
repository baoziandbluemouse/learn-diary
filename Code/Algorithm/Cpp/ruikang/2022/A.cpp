#include<bits/stdc++.h>
using namespace std;
using ll = long long;


void solve()
{
	int n,m;
	cin>>n>>m;
	int cnt = 0;
	int sum = 0;
	for(int i = 1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(sum+x>m)
		{
			sum=0;
			cnt++;
		}
		sum+=x;
	}
//	if(sum>m)
//	{
//		cnt++;
//	}
	cout<<cnt<<"\n";
}

int main()
{
	int _=1;
	//cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}
