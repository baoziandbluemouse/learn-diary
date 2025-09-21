#include <bits/stdc++.h>
using namespace std;
const int N = 10;
using ll = long long;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    priority_queue<pair<double, ll>> q;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        q.push({x, 1});
    }
    while (m)
    {
        double x = q.top().first;
        ll c = q.top().second;
        q.pop();
        if (m >= c)
        {
            m -= c;
            q.push({x / 2, c * 2});
        }
        else
        {
            q.push({x, c - m});
            q.push({x / 2, m * 2});
            m = 0;
        }
    }
    while (!q.empty())
    {
        double x = q.top().first;
        ll c = q.top().second;
        q.pop();
        if (k <= c)
        {
            cout << fixed << setprecision(18) << x << "\n";
            break;
        }
        else
        {
            k -= c;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}