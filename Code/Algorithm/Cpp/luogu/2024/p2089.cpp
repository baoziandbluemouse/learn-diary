#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000
#define MAX 30 // 多于这个克数直接输出0
#define MIN 10 // 少于直接输出0
int arr[MAXN][MAX];
int temp[MAX];
int cnt = 0;
void dfs(int x, int sum); // x代表第几种香料 香料克数必须在1-3中选择 深度优先
int n;
int main(void)
{
    cin >> n;

    if (n > MAX || n < MIN)
    {
        cout << 0 << "\n";
    }
    else
    {
        dfs(1, 0);
        cout << cnt << "\n";
        for (int i = 1; i <= cnt; i++)
        {
            for (int j = 1; j <= MIN; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}

void dfs(int x, int sum)
{
    if (sum > n)
    {
        return;
    }
    if (x > MIN)
    {
        if (sum == n)
        {
            cnt++;
            for (int i = 1; i <= MIN; i++)
            {
                arr[cnt][i] = temp[i];
            }
        }
        return;
    }
    for (int i = 1; i <= 3; i++)
    {
        temp[x] = i;
        dfs(x + 1, sum + i);
        temp[x] = 0; // 恢复
    }
}