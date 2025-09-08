#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
const int N = 1e5+10;
ll p[N];
ll qmi(ll x, ll y) {
	ll res = 1;
	while(y) {
		if(y&1) {
			res = res*x%MOD;
		}
		y>>=1;
		x=x*x%MOD;
	}
	return res%MOD;
}

ll inv(ll b) {
	return qmi(b,MOD-2);
}

int main() {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		ll a,b;
		cin>>a>>b;
		p[i]=a*inv(b)%MOD;
	}
	cout<<p[1]<<"\n";
	return 0;
}
