#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
using ll = long long;
int a[N];
int main() {
	int n,x,q;
	cin>>n>>q>>x;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	while(q--) {
		bool flag = false;
		int l,r;
		cin>>l>>r;
		int b = 0;
		for(int i = l; i<=r-1; i++) {
			b = x^a[i];
			for(int j=i+1; j<=r; j++) {
				if(b == a[j]) {
					flag = true;
					break;
				}
			}
			if(flag) {
				break;
			}
		}
		if(flag) {
			cout<<"yes"<<"\n";
		} else {
			cout<<"no"<<"\n";
		}
	}
	return 0;
}
