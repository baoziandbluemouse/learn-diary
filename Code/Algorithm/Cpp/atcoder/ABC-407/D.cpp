#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;
ll a[20], ans;
bool vis[20];

void dfs(int step)
{
    if (step > n * m - 1)
    {
        ll sum = 0;
        for (int i = 0; i < n * m; i++)
        {
            if (!vis[i])
            {
                sum ^= a[i];
            }
        }
        ans = max(ans, sum);
        return;
    }
    // 第一种，不做操作
    dfs(step + 1);
    if (!vis[step])
    {
        vis[step] = 1;
        // 往右放，不能是最后一列,右边的格子不能被访问过
        if (step % m < m - 1 && !vis[step + 1])
        {
            vis[step + 1] = 1;
            dfs(step + 2);
            vis[step + 1] = 0;
            // 回溯
        }
        // 往下放，不能是最后一行，下面的格子不能被访问过
        if (step / m < n - 1 && !vis[step + m])
        {
            vis[step + m] = 1;
            dfs(step + 1);
            vis[step + m] = 0;
        }
        // 回溯
        vis[step] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n * m; i++)
    {
        cin >> a[i];
    }
    dfs(0);
    cout << ans << "\n";
    return 0;
}