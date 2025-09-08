#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
using ll = long long;
const int  N = 1e3+10;
int p1[N],p2[N],p3[N];
int front1,front2,front3,back1,back2,back3;
int idx1,idx2,idx3;
int sum;
int cal[5];

int check(int a,int b,int c)
{
	//1和2是一组，3和4是一组，先看1和2
	if(a == b || b == c || a == c)
	{
		if(a == b && b == c)
		{
			return 200;
		}
		return 100;
	}
	else
	{
		if(a+2 == b+1 && b+1 == c)
		{
			return 200;
		}
		cal[1]=a,cal[2]=b,cal[3]=c;
		sort(cal+1,cal+3+1);
		if(cal[1] +2 == cal[2] +1 && cal[2]+1 == cal[3])
		{
			return 100;
		}
	}
	return 0; 
}




void solve()
{
	//三次约瑟夫问题，然后再check
	int m1,m2,m3;
	cin>>m1>>m2>>m3;
	idx1=(idx1+m1)%back1;
	idx2=(idx2+m2)%back2;
	idx3=(idx3+m3)%back3;
	int a = p1[idx1];
	int b = p2[idx2];
	int c = p3[idx3];
	int get = check(a,b,c);
	sum+=get;
}


int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		p1[back1++]=x;
	} 
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		p2[back2++]=x;
		
	}
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		p3[back3++]=x;
	}
	int _t;
	cin>>_t;
	while(_t--)
	{
		solve();
	}
	cout<<sum<<"\n";
	return 0;
}
