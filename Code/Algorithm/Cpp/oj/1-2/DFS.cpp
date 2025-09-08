#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 30
using namespace std;
int sta[N];
int n;

void dfs(int x);

int main(void)
{
    cin >> n;
    dfs(1);
    return 0;
}

void dfs(int x) // x代表当前枚举到了哪个位置
{
    if (x > n)
    {
        for (int i = 1; i <= n; i++)
        {
            if (sta[i] == 1)
            {
                printf("%d ", i);
            }
        }
        cout << "\n";
        return;
    }
    // 选
    sta[x] = 1;
    dfs(x + 1);
    sta[x] = 0; // 恢复现场

    // 不选
    sta[x] = 2;
    dfs(x + 1);
    sta[x] = 0; // 恢复现场
}
