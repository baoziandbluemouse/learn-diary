#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 55;
int c[N];

void solve()
{
	int n,w;
	cin>>n>>w;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int a=0,b=0;
	for(int i=1;i<=n;i++){
		if(c[i]>=35){
			if(w!=4){
				a++;
			}else{
				b++;
			}
		}
		w%=7;
		w++;
	}
	cout<<a<<" "<<b<<"\n";
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
