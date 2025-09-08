#include<bits/stdc++.h>
using ll = long long;
const int N = 2e5+10;
ll a[N];
ll x[N],y[N],z[N];
struct node {
	ll val;
	int num;
	bool operator<(const node &b) const {
		return (b.val != val)? b.val<val : b.num<num;
	}
};

node g[N];
int main() {
	int n;
	ll l;
	cin>>n>>l;
	for(int i=1; i<=n; i++) {
		cin>>x[i]>>y[i]>>z[i];
	}
	
}
