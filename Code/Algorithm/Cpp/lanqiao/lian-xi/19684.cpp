#include <bits/stdc++.h>
using namespace std;
bitset<10> vis;
int a[10];
int n;

void dfs(int dep)
{
    if (dep > n)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            a[dep] = i;
            vis[i] = true;
            dfs(dep + 1);
            vis[i] = false;
            a[dep] = 0;
        }
    }
}

int main()
{
    cin >> n;
    dfs(1);
    return 0;
}