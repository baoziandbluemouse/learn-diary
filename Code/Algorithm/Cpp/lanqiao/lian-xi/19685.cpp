#include <iostream>
using namespace std;
const int N = 20;
int a[N];
int n;
void dfs(int dep)
{
    if (dep > n)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 1)
            {
                cout << i << " ";
            }
        }
        cout << "\n";
        return;
    }
    // 不选
    a[dep] = 0;
    dfs(dep + 1);
    // 选
    a[dep] = 1;
    dfs(dep + 1);
}
int main()
{
    cin >> n;
    dfs(1);
    return 0;
}