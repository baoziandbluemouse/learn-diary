#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
using ll = long long;
int n,k;
const int N = 1e6+10;
int a[N];
void init()
{
	for(int i=0;i<=15;i++)
	{
		a[(1<<i)]=1;
	}
	for(int i=1;i<=15;i++)
	{
		int x = (1<<i)-1;
		if(x&1)
		{
			a[x]=1;
		}
		else
		{
			a[x]=2;
		}
	}
	a[5]=a[6]=a[9]=a[10]=a[12]=a[17]=a[18]=a[20]=a[23]=a[24]=a[27]=a[29]=a[30]=2;
	a[11]=a[13]=a[14]=a[16]=a[19]=a[21]=a[22]=a[25]=a[26]=a[28]=1;
	
}

void solve()
{
	cin>>n>>k;
	int x = (1<<(n-1)) -1 + k;
	if(n == 1 && k == 1)
	{
		cout<<"RED\n";
		return;
	}
	if(a[x] == 1)
	{
		cout<<"RED\n";
	}
	else
	{
		cout<<"BLACK\n";
	}
}


int main()
{
	int _t;
	cin>>_t;
	while(_t--)
	{
		solve();
	}
	return 0;
}
