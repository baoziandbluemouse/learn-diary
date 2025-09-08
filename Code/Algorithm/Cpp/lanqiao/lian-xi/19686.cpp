#include <iostream>
using namespace std;
const int N = 30;
int a[N];
int n, m;

void dfs(int dep, int start)
{
    if (dep > m)
    {
        for (int i = 1; i <= m; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = start; i <= n; i++)
    {
        a[dep] = i;
        dfs(dep + 1, i + 1);
        a[dep] = 0;
    }
}

int main()
{
    cin >> n >> m;
    dfs(1, 1);
    return 0;
}