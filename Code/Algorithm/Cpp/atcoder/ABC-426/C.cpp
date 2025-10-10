#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int t[N];
void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        t[i] = 1;
    }
    int cur = 1;
    // 当前最老的是第几代
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        int tot = 0; // 记录从cur升级到x，总共有多少
        while (cur <= x)
        {
            tot += t[cur];
            t[y] += t[cur];
            t[cur] = 0;
            cur++;
        }
        cout << tot << "\n";
    }
}

int main()
{
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}