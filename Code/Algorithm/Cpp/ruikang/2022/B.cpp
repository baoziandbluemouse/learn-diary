#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1010;
int a[N];
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int>las(n+1,-1);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		int t,k;
		cin>>t>>k;
		for(int i=1;i<=k;i++)
		{
			int x;
			cin>>x;
			if(las[x] !=-1 && t-las[x] < a[x])
			{
				printf("Don't take %d at %d!\n",x,t);
				continue;
			}
			las[x]=t;
		}
	}
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
