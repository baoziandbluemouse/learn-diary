#include <bits/stdc++.h>
using namespace std;
const int N = 105;
bool col[N];     // 存储列状态
bool ls[N];      // 存储左对角线状态
bool rs[N];      // 存储右对角线状态，由于右对角线可能有负数，所以整体平移
int arr[N];      // 记录每行选了哪一列
int ans[100][N]; // 记录答案
void dfs(int x); // x代表当前到第几行
int cnt = 1;
int main(void)
{
    int k, b;
    cin >> k;
    dfs(1);
    while (k--)
    {
        cin >> b;
        for (int i = 1; i <= 8; i++)
        {
            cout << ans[b][i];
        }
        cout << "\n";
    }
    return 0;
}

void dfs(int x)
{
    if (x > 8)
    {
        for (int i = 1; i <= 8; i++)
        {
            ans[cnt][i] = arr[i];
        }
        cnt++;
        return;
    }

    for (int i = 1; i <= 8; i++)
    {
        if (!col[i] && !ls[i + x] && !rs[i - x + 8])
        {
            col[i] = true;
            ls[i + x] = true;
            rs[i - x + 8] = true;
            arr[x] = i;
            dfs(x + 1);
            col[i] = false;
            ls[i + x] = false;
            rs[i - x + 8] = false;
            arr[x] = 0;
        }
    }
}
