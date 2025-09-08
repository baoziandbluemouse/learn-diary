#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int cal(string s,string cmp,int n)
{
	int dif = 0;
	for(int i=0;i<2*n;i++)
	{
		if(s[i] != cmp[i%2])
		{
			dif++;
		}
	}
	return dif/2;
}

void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int cost1 = cal(s,"AB",n);
	int cost2 = cal(s,"BA",n);
	cout<<min(cost1,cost2)<<"\n";
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
}
