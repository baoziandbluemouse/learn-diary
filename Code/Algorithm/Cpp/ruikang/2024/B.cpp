#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 25;
int cal[N];
int cnt[25] = {0, 12, 9, 7, 5, 4, 3, 3, 2, 2, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
void solve()
{
	int n;
	cin >> n;
	while (n--)
	{
		for (int i = 1; i <= 20; i++)
		{
			int a, b;
			cin >> a >> b;
			int val = cnt[a] + b;
			cal[i] += val;
		}
	}
	for (int i = 1; i <= 20; i++)
	{
		cout << i << " " << cal[i] << "\n";
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
