#include <cstdio>
#include <algorithm>
#include <iostream>
#define N 25
using namespace std;
int arr[N];
int n, r;

void dfs(int x, int start); // x记录枚举到哪个位置，start记录当前位置从几开始枚举

int main(void)
{
    cin >> n >> r;
    dfs(1, 1);
    return 0;
}

void dfs(int x, int start)
{
    if (x > r)
    {
        for (int i = 1; i <= r; i++)
        {
            printf("%3d", arr[i]);
        }
        printf("\n");
        return;
    }
    for (int i = start; i <= n; i++)
    {
        arr[x] = i;
        dfs(x + 1, i + 1);
        arr[x] = 0;
    }
}