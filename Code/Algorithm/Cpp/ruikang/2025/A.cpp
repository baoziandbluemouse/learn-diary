#include<bits/stdc++.h>
using namespace std;
using ll = long long;


void solve()
{
	int n;
	cin>>n;
	while(n--)
	{
		int m,d,p;
		cin>>m>>d>>p;
		if(m > 7)
		{
			cout<<"Too late!\n";
			continue;
		}
		if(m == 7)
		{
			if(d < 12)
			{
				if(p >=2000)
				{
					if(p == 2000)
					{
						cout<<"Ok!\n";
					}
					else
					{
						cout<<"^_^\n";
					}
				}
				else
				{
					cout<<"Need more!\n";
				}	
			}
			else
			{
				cout<<"Too late!\n";
			}
			continue;
		}
		else if(m == 6)
		{
			if(d<=20)
			{
				if(p >= 1800)
				{
					if(p == 1800)
					{
						cout<<"Ok!\n";
					}
					else
					{
						cout<<"^_^\n";
					}
				}
				else
				{
					cout<<"Need more!\n";
				}	
			}
			else
			{
				if(p >=2000)
				{
					if(p == 2000)
					{
						cout<<"Ok!\n";
					}
					else
					{
						cout<<"^_^\n";
					}
				}
				else
				{
					cout<<"Need more!\n";
				}	
			}
		}
		else
		{
			if(p >= 1800)
			{
				if(p == 1800)
				{
					cout<<"Ok!\n";
				}
				else
				{
					cout<<"^_^\n";
				}
			}
			else
			{
				cout<<"Need more!\n";
			}
		}
	}
}




int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int _ = 1;
	//cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}
