#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
using ll = long long;
const int N = 1e6+10;
int n,k;
int tree[N];
//void dfs(int dep,int f_color) //cnt代表总的 1代表红，2代表黑 
//{
//	if(dep>n)
//	{
//		if(cnt == ((1<<(n-1)) -1 + k ))
//		{
//			if(f_color == 1)
//			{
//				cout<<"RED\n";
//			}
//			else if(f_color == 2)
//			{
//				cout<<"BLACK\n";
//			}
//		}
//		return;
//	}
//	
//	if(f_color == 1)
//	{
//		//左
//		cnt++; 
//		dfs(dep+1,1);
//		cnt--;
//		//右
//		cnt++;
//		dfs(dep+1,2); 
//	}
//	else if(f_color == 2)
//	{
//		//左
//		cnt++;
//		dfs(dep+1,2);
//		cnt--;
//		//右
//		cnt++;
//		dfs(dep+1,1); 
//	}
//}

void solve()
{
	cin>>n>>k;
	if(n == 1 && k == 1)
	{
		cout<<"RED\n";
		return;
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
}
