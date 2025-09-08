#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
using ll = long long;
const int N = 1e5+10;


bool check(int n)
{
	if(n<2)
	{
		return false;
	}
	for(int i=2;i*i<=n;i++)
	{
		if(n%i == 0)
		{
			return false;
		}
	}
	return true;
}



void solve()
{
	bitset<N>vis; //1代表不是质数 
	vis[0]=vis[1]=1;
	for(int i=2;i<=N;i++)
	{
		if(!vis[i])
		{
			for(int j=i*2;j<=N;j+=i)
			{
				vis[j]=1;
			}
		}
	}
	int cnt = 0;
	for(int i=2;i<=N;i++)
	{
		if(!vis[i])
		{
			cnt++;
			if(cnt<=10)
			{
				cout<<i<<"\n";
			}
		}
		if(cnt == 2025)
		{
			cout<<i<<"\n";
			cout<<check(i)<<"\n";
			cout<<cnt<<"\n";
			return;
		}
	}
	if(cnt < 2025)
	{
		cout<<"NO"<<"\n";
	}
}


int main()
{
	int _t;
	cin>>_t;
	while(_t--)
	{
		solve();
	}
}
