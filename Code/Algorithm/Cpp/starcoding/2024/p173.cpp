#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 20;
ll x[N], y[N], a[N];
bitset<N> st;
ll b[N];
int n, k;
ll dfs(int depth, ll sum);
ll getabs(ll x)
{
    return x > 0 ? x : -x;
}
ll getDist(int i, int j)
{
    return getabs(x[i] - x[j]) + getabs(y[i] - y[j]);
}
int main(void)
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> x[i] >> y[i] >> a[i];
        }
        cout << dfs(1, 0) << "\n";
    }
    return 0;
}

ll dfs(int depth, ll sum)
{
    if (depth > k)
    {
        return sum;
    }
    ll res = -0x3fffffff;
    for (int i = 1; i <= n; i++)
    {
        if (st[i])
        {
            continue;
        }
        st[i] = 1;
        b[depth] = i;
        res = max(res, dfs(depth + 1, sum + a[i] - getDist(b[depth - 1], i)));
        b[depth] = 0;
        st[i] = 0;
    }
    return res;
}
