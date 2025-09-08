#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N =1100;
int a[N];

int cal()
{
	int max_len = 0;
	int len = 0;
	for(int i=1; i<=n+1; i++) {
		if(a[i] == 0) {
			len++;
			max_len = max(len,max_len);
		} else {
			len=0;
		}
	}
}

int main() {
	int n;
	ll x;
	cin>>n>>x;
	if(n>1000) {
		cout<<n<<"\n";
		return 0;
	}
	ll sum = 0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		sum+=a[i];
	}
	if(sum == x) {
		cout<<n<<"\n";
		return 0;
	}
	int k = 0;
	for(ll i=1;i<=x*2;i++)
	{
		k = cal();
		for(int j = )
	}

	return 0;
}
