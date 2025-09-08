#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string s[201];
map<string,string> s1,s2;


void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		s1[x]=y;
	}
	for(auto &a:s1){
		for(auto &b:s1){
			string c = a.first + b.first;
			string d = a.second + b.second;
			if(s2.find(c) == s2.end()){
				s2[c] = d;
			}else{
				s2[c] = "D";
			}
		}
	}
	for(int i=1;i<=m;i++){
		string x;
		cin>>x;
		if(s1.find(x) != s1.end()){
			cout<<s1[x]<<"\n";
		}
		else{
			if(s2.find(x) == s2.end()){
				cout<<"D\n";
			}else{
				cout<<s2[x]<<"\n";
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int _=1;
	//cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}
