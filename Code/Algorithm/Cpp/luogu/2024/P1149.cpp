#include <bits/stdc++.h>
using namespace std;

int digitcost[1100] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int arr[5];
int n;
int cnt;
void dfs(int x, int sum);
int main(void)
{
    cin >> n;
    for (int i = 10; i <= 1000; i++)
    {
        digitcost[i] = digitcost[i / 10] + digitcost[i % 10]; // digitcost[1000] = digitcost[100] + digitcost[0] 递推
    }
    dfs(1, 0);
    cout << cnt << "\n";
    return 0;
}
void dfs(int x, int sum)
{
    if (sum > n - 4)
    {
        return;
    }
    if (x > 3)
    {
        if (sum == n - 4 && arr[1] + arr[2] == arr[3])
        {
            cnt++;
        }
        else
        {
            return;
        }
    }
    for (int i = 0; i <= 1000; i++)
    {
        arr[x] = i;
        dfs(x + 1, sum + digitcost[i]);
        arr[x] = 0;
    }
}
