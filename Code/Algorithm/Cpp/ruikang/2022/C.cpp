#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1100;
ll minn = 0,maxx = 0;
int ans[N];
void do1(string t)
{
	int len = t.size();
	int cnt = 0,p = 0;
	if(t.find("d") == string::npos)
	{
		int temp = 0;
		for(int i=1;i<len;i++)
		{
			temp = temp*10 + (t[i]-'0');
		}
		if(t[0] == '+')
		{
			minn+=temp;
			maxx+=temp;
		}
		else{
			minn-=temp;
			maxx-=temp;
		}
		return;
	}
	else{
		int pos = t.find("d");
		if(t[pos-1]>='1' && t[pos-1] <= '9')
		{
			cnt = t[pos-1]-'0';
		}else{
			cnt = 1;
		}
		p = t[pos+1]-'0';
		if(t[0] == '+')
		{
			minn = minn + (cnt*1);
			maxx = maxx + (cnt*p);
		}else{
			minn = minn - (cnt*p);
			maxx = maxx - (cnt*1);
		}
	}
	ans[p]+=cnt;
}




void solve()
{
	string s;
	cin>>s;
	s = "+" + s;
	int las = 0,i = 0;
	int len = s.size();
	for(i=0;i<len;i++)
	{
		if(i!= las && (s[i] == '+' || s[i] == '-'))
		{
			string temp = s.substr(las,i-las);
			do1(temp);
			las = i;
		}
	}
	if(i!=las)
	{
		string temp = s.substr(las,i-las);
		do1(temp);
	}
	for(int i=2;i<=1000;i++)
	{
		if(ans[i])
		{
			cout<<i<<" "<<ans[i]<<"\n";
		}
	}
	cout<<minn<<" "<<maxx<<"\n";
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
