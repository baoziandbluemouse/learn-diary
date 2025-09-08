#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
using ll = long long;
const int N = 1e3+10;
int dp[N][N];
bool check(string s)
{
	vector<int>a;
	int n = s.size();
	if(n == 1)
	{
		return true;
	}
	for(int i=0;i<n;i++)
	{
		int x = s[i]-'0';
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	int m = a.size();
	for(int i=0;i<m;i++)
	{
		if(a[i] != a[i+1] || a[i]+1 !=a[i+1])
		{
			return false;
		}
	}
	return true;
}


int main()
{
	string s;
	cin>>s;
	ll cnt = 0;
	int n = s.size();
	for(int i=0;i<n;i++)
	{
		dp[i][i]=1;
		for(int j=i;j<n;j++)
		{
			for(int k=i;k<j;k++)
			{
				string s=
			}
		}
	}
	cout<<cnt<<"\n";
	return 0;
}
