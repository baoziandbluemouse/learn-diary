#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	char a,b;
	cin>>a>>b;
	string s;
	cin>>s;
	stack<char>stk;
	int len = s.size();
	int ans = 0;
	for(int i=0;i<len;i++)
	{
		if(stk.size() && stk.top() == a)
		{
			if(s[i] == b)
			{
				stk.pop();
				ans++;
				continue;
			}
		}
		stk.push(s[i]);
	}
	string t;
	while(stk.size())
	{
		t+=stk.top();
		stk.pop();
	}
	int length = t.size();
	cout<<ans<<" ";
	for(int i=length-1;i>=0;i--)
	{
		cout<<t[i];
	}
	cout<<"\n";
}


int main()
{
	int _ = 1;
	//cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}
