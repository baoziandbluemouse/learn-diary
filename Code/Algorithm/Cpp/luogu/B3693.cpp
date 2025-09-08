#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
using ull = unsigned long long;
ull prefix[N][N];
ull a[N][N];


void solve() {
	memset(prefix,0,sizeof(prefix));
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin>>a[i][j];
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+a[i][j];
		}
	}
	ull ans = 0;
	for(int i=1; i<=q; i++) {
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		ans^=(prefix[c][d]-prefix[a-1][d]-prefix[c][b-1]+prefix[a-1][b-1]);
	}
	cout<<ans<<"\n";
}






int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) {
		solve();
	}
	return 0;
}
