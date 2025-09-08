#include <iostream>
#include <string>
#include <bitset>
using namespace std;
char b[] = {'0', 'A', 'B', 'C', 'D'};
int a[5];
bitset<10> vis;
int n;
void dfs(int dep)
{
    if (dep > n)
    {
        bool flag = false;
        for (int i = 1; i <= n; i++)
        {
            if (!flag)
            {
                cout << b[a[i]];
                flag = true;
            }
            else
            {
                cout << "+" << b[a[i]];
            }
        }
        cout << " Problem\n";
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            a[dep] = i;
            dfs(dep + 1);
            a[dep] = 0;
            vis[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    dfs(1);
    return 0;
}