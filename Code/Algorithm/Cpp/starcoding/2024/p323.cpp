#include <bits/stdc++.h>
using namespace std;
const int N = 15;
typedef long long ll;
ll a[N];
ll b[N];
vector<int> st(100);
int n, m;
ll maxx;
ll dfs(int depth, ll sum);

int main(void)
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> b[i];
        }
        maxx = 0;
        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + m);
        for (int i = n, j = m; j >= 1; i--, j--)
        {
            maxx += a[i] * b[j];
        }
        st.clear();
        cout << dfs(1, 0) << "\n";
    }
    return 0;
}

ll dfs(int depth, ll sum) // 这题depth以m为界，即人为位置，座位为方案（为每个同学分配座位）
{
    if (depth > m)
    {
        return (ll)(sum >= maxx / 2);
    }
    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            st[i] = 1;
            res += dfs(depth + 1, sum + a[i] * b[depth]);
            st[i] = 0;
        }
    }
    return res;
}