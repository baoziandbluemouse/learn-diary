#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2000;
char g[N][N];
int vis[N][N];
int n, m;
bool check(int x, int y)
{
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (i <= 0 || i >= n + 1 || j <= 0 || j >= m + 1)
			{
				continue;
			}
			if (g[i][j] == 'm')
			{
				return false;
			}
		}
	}
	return true;
}

void do1(int x, int y)
{
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (i <= 0 || i >= n + 1 || j <= 0 || j >= m + 1)
			{
				continue;
			}
			if (g[i][j] == '.' && vis[i][j] != -1)
			{
				vis[i][j] = 1;
			}
		}
	}
}

void do2(int x, int y)
{
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (i <= 0 || i >= n + 1 || j <= 0 || j >= m + 1)
			{
				continue;
			}
			vis[i][j] = -1;
		}
	}
}

void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> g[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (g[i][j] == 'w')
			{
				if (check(i, j))
				{
					do1(i, j);
				}
			}
			else if (g[i][j] == 'c')
			{
				do2(i, j);
			}
		}
	}
	bool flag = false;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (vis[i][j] == 1)
			{
				cout << i << " " << j << "\n";
				flag = true;
			}
		}
	}
	if (!flag)
	{
		cout << "Too cold!" << "\n";
	}
}

int main()
{
	int _ = 1;
	// cin>>_;
	while (_--)
	{
		solve();
	}
	return 0;
}
