#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000
int arr[MAXN];
int st[MAXN];   // 记录每个数选没选过
int mars[MAXN]; // 记录火星人给的排列
int n, m;
int cnt = 0;
bool flag = false;
void dfs(int x);
int main(void)
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> mars[i];
    }
    dfs(1);
    return 0;
}

void dfs(int x)
{
    if (x > n)
    {
        cnt++;
        if (cnt == m + 1)
        {
            for (int i = 1; i <= n; i++)
            {
                if (flag)
                {
                    cout << " ";
                }
                flag = true;
                cout << arr[i];
            }
            cout << "\n";
            exit(0);
        }
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!cnt)
        {
            i = mars[x];
        }
        if (!st[i])
        {
            arr[x] = i;
            st[i] = 1;
            dfs(x + 1);
            st[i] = 0;
            arr[x] = 0;
        }
    }
}