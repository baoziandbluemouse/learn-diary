#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int cnt = 0;
int n;
void dfs(int x); // x代表第几步
void dfs2(int x);
int main(void)
{
    cin >> n;
    dfs(1);
    cout << cnt << "\n";
    return 0;
}

void dfs(int x)
{
    if (x > n)
    {
        cnt++;
        return;
    }
    for (int i = 1; i <= 3; i++)
    {
        if (i == 1)
        {
            dfs(x + 1);
        }
        else
        {
            dfs2(x + 1);
        }
    }
}

void dfs2(int x)
{
    if (x > n)
    {
        cnt++;
        return;
    }
    for (int i = 1; i <= 2; i++)
    {
        if (i == 1)
        {
            dfs(x + 1);
        }
        else
        {
            dfs2(x + 1);
        }
    }
}
