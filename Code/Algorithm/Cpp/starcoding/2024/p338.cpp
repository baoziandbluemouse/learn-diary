#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
ll bfs(ll x, ll y);
int main(void)
{
    int T;
    ll a, b;
    cin >> T;
    while (T--)
    {
        cin >> a >> b;
        ll ans = bfs(a, b);
        cout << ans << "\n";
    }
    return 0;
}

ll bfs(ll x, ll y)
{
    vector<int> f(N, -1);
    queue<int> q;
    q.push(x);
    f[x] = 0;
    if (x == y)
        return 0;
    while (q.size())
    {
        int t = q.front();
        q.pop();
        for (int i = 1; i <= 3; i++)
        {
            int v;
            if (i == 1)
            {
                v = t * 1.6;
            }
            else if (i == 2)
            {
                v = t * 0.6;
            }
            else if (i == 3)
            {
                v = t + 1;
            }
            if (v > 2e6 || f[v] != -1)
            {
                continue;
            }
            f[v] = f[t] + 1;
            if (v == y)
                return f[v];
            q.push(v);
        }
    }
    return 0;
}