#include<iostream>
#include<map>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	map<int,int>mp;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		mp[x]=i;
	}
	int q;
	cin>>q;
	while(q--)
	{
		int x;
		cin>>x;
		if(mp.count(x))
		{
			cout<<mp[x]<<"\n";
		}
		else
		{
			cout<<0<<"\n";
		}
	}
	return 0;
}
