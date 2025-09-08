#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int pos[N];
bitset<N> vis;
int n;
void dfs(int dep) // x代表深度
{
    if (dep > n)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << pos[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            pos[dep] = i;
            vis[i] = true;
            dfs(dep + 1);
            // 回溯
            vis[i] = false;
            pos[dep] = 0;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    dfs(1);
    return 0;
}