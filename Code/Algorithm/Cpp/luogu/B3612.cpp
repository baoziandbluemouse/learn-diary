#include<iostream>
using namespace std;
const int N = 1e5+10;
using ll = long long;
int a[N];
ll prefix[N];

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		prefix[i]=prefix[i-1]+a[i];
	}
	int m;
	cin>>m;
	while(m--)
	{
		int l,r;
		cin>>l>>r;
		cout<<prefix[r]-prefix[l-1]<<"\n";
	}
	return 0;
}
