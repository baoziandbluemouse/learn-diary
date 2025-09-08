#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int a[N], pr[N], bd[N], vis[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        pr[i] = pr[i - 1];
        if (vis[a[i]] == 0)
        {
            vis[a[i]]++;
            pr[i]++;
        }
    }
    memset(vis, 0, sizeof(vis));
    for (int i = n; i >= 1; i--)
    {
        bd[i] = bd[i + 1];
        if (vis[a[i]] == 0)
        {
            vis[a[i]]++;
            bd[i]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, pr[i] + bd[i + 1]);
    }
    cout << ans << "\n";
    return 0;
}