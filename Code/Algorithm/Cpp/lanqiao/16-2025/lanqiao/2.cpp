#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
using ll = long long;
const int N = 10;
int g[N][N];
int cnt_0, cnt_1;

bool check()
{
	// �����жϺڰ����Ƿ����
	if (cnt_0 != cnt_1 || cnt_0 != 18 || cnt_1 != 18)
	{
		return false;
	}
	// �����ж��Ƿ��г�����1������0
	// ���ж����Ƿ�����1
	for (int i = 1; i <= 6; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= 6; j++)
		{
			if (g[i][j] == 1)
			{
				cnt++;
				if (cnt == 3)
				{
					return false;
				}
			}
			if (g[i][j] == 0)
			{
				cnt = 0;
			}
		}
	}
	for (int i = 1; i <= 6; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= 6; j++)
		{
			if (g[i][j] == 0)
			{
				cnt++;
				if (cnt == 3)
				{
					return false;
				}
			}
			if (g[i][j] == 1)
			{
				cnt = 0;
			}
		}
	}
	// �ж���
	for (int j = 1; j <= 6; j++)
	{
		int cnt = 0;
		for (int i = 1; i <= 6; i++)
		{
			if (g[i][j] == 1)
			{
				cnt++;
				if (cnt == 3)
				{
					return false;
				}
			}
			if (g[i][j] == 0)
			{
				cnt = 0;
			}
		}
	}
	for (int j = 1; j <= 6; j++)
	{
		int cnt = 0;
		for (int i = 1; i <= 6; i++)
		{
			if (g[i][j] == 0)
			{
				cnt++;
				if (cnt == 3)
				{
					return false;
				}
			}
			if (g[i][j] == 1)
			{
				cnt = 0;
			}
		}
	}
	// �ж�ÿ���Ƿ�Ψһ
	for (int i = 1; i <= 6; i++)
	{
		for (int j = i + 1; j <= 6; j++)
		{
			if (g[i][1] != g[j][1])
			{
				continue;
			}
			if (g[i][2] != g[j][2])
			{
				continue;
			}
			if (g[i][3] != g[j][3])
			{
				continue;
			}
			if (g[i][4] != g[j][4])
			{
				continue;
			}
			if (g[i][5] != g[j][5])
			{
				continue;
			}
			if (g[i][6] != g[j][6])
			{
				continue;
			}
			return false;
		}
	}
	// �ж�ÿ���Ƿ�Ψһ
	for (int i = 1; i <= 6; i++)
	{
		for (int j = i + 1; j <= 6; j++)
		{
			if (g[1][i] != g[1][j])
			{
				continue;
			}
			if (g[2][i] != g[2][j])
			{
				continue;
			}
			if (g[3][i] != g[3][j])
			{
				continue;
			}
			if (g[4][i] != g[4][j])
			{
				continue;
			}
			if (g[5][i] != g[5][j])
			{
				continue;
			}
			if (g[6][i] != g[6][j])
			{
				continue;
			}
			return false;
		}
	}
	return true;
}

void dfs(int x, int y) // x�����У�y������
{
	if (y > 6) // ����
	{
		dfs(x + 1, 1); // ��һ��
	}
	else if (x > 6) // ����
	{
		if (check())
		{
			for (int i = 1; i <= 6; i++)
			{
				for (int j = 1; j <= 6; j++)
				{
					cout << g[i][j];
				}
			}
			exit(0);
		}
		else
		{
			return;
		}
	}
	// ��δ��
	if (y > 6)
	{
		return;
	}
	// ѡ����1
	g[x][y] = 1;
	cnt_1++;
	dfs(x, y + 1);
	cnt_1--;
	g[x][y] = -1;
	// ѡ����0
	g[x][y] = 0;
	cnt_0++;
	dfs(x, y + 1);
	cnt_0--;
	g[x][y] = -1;
}

void solve()
{
	memset(g, -1, sizeof(g));
	dfs(1, 1);
}

int main()
{
	int _t;
	_t = 1;
	while (_t--)
	{
		solve();
	}
	return 0;
}
