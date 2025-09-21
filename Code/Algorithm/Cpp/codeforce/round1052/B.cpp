#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    // 一个桶数组,至少要能加完一次
    cin >> n >> m;
    vector<int> p(m + 1, 0);
    // 每个集合的和不同
    vector<vector<int>> a(n + 1, vector<int>());
    ll sum = 0;
    for (int i = 1; i <= m; i++)
    {
        sum += i;
    }
    vector<int> cnt(sum + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int s;
        cin >> s;
        for (int j = 1; j <= s; j++)
        {
            int x;
            cin >> x;
            a[i].push_back(x);
            p[x]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (p[i] == 0)
        {
            cout << "No\n";
            return;
        }
    }
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