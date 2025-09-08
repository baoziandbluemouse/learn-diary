#include<bits/stdc++.h>
using namespace std;
using ll = long long;


void solve()
{
	int fa=0,fb=0,fc=0,sa=0,sb=0,sc=0;
	int n;
	cin>>n;
	while(n--)
	{
		int op,t;
		cin>>op>>t;
		if(op == 0)
		{
			if(t == 1){
				fa++;
			}else if(t == 2){
				fb++;
			}else if(t == 3){
				fc++;
			}
		}
		else
		{
			if(t == 1){
				sa++;
			}else if(t == 2){
				sb++;
			}else if(t == 3){
				sc++;
			}
		}
	}
	bool flag = false;
	if(fa!=sa){
		flag = (fa>sa);
	}else if(fb!=sb){
		flag = (fb>sb);
	}else{
		flag = (fc>sc);
	}
	
	if(flag){
		cout<<fa<<" "<<fb<<" "<<fc<<"\n";
		cout<<sa<<" "<<sb<<" "<<sc<<"\n";
		cout<<"The first win!\n";
	}else{
		cout<<fa<<" "<<fb<<" "<<fc<<"\n";
		cout<<sa<<" "<<sb<<" "<<sc<<"\n";
		cout<<"The second win!\n";
	}
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
