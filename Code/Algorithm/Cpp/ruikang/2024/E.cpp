#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e3 + 10;
struct node
{
	int t;
	int d;
	int p;
	bool operator<(const node &b) const
	{
		if (d != b.d)
		{
			return d < b.d;
		}
		else if (t != b.t)
		{
			return t < b.t;
		}
		else
		{
			return p < b.p;
		}
	}
};
vector<node> data;
void solve()
{
	int len = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a > b)
		{
			continue;
		}
		data.push_back({a, b, c});
	}
	ll f[N * 3] = {0};
	ll sum = -1;
	for (auto &edge : data)
	{
		int t = edge.t;
		int d = edge.d;
		int p = edge.p;
		for (int i = d; i >= 0; i--)
		{
			if (i >= t)
			{
				f[i] = max(f[i], f[i - t] + p);
				sum = max(f[i], sum);
			}
		}
	}
	cout << sum << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int _;
	cin >> _;
	while (_--)
	{
		solve();
	}
	return 0;
}
